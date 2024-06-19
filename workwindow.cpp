#include "workwindow.h"
#include "ui_workwindow.h"

namespace monitoring {
 WorkWindow::WorkWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::WorkWindow),
    chooseTheProject(new ChooseTheProject(parent)) {
     ui->setupUi(this);
 }

 WorkWindow::~WorkWindow() {
     delete ui;
     delete chooseTheProject;
 }

 // Ask to server about data of project, then draw it in client
 void WorkWindow::drawPlots(QString project) {

     // Идем к серверу, получаем по названию проекта нужные данные,
     // которые в последующем отрисовываются
     std::vector<std::pair<QString, QString>> currentProject = server.openProject(project);
     plot.addGraph();
     plot.graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
     plot.graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
     plot.addGraph();
     plot.graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
     // generate some points of data (y0 for first, y1 for second graph):
     QVector<double> x(251), y0(251), y1(251);
     for (int i=0; i<251; ++i)
     {
       x[i] = i;
       y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
       y1[i] = qExp(-i/150.0);              // exponential envelope
     }
     // configure right and top axis to show ticks but no labels:
     // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
     plot.xAxis2->setVisible(true);
     plot.xAxis2->setTickLabels(false);
     plot.yAxis2->setVisible(true);
     plot.yAxis2->setTickLabels(false);
     // make left and bottom axes always transfer their ranges to right and top axes:
     connect(plot.xAxis, SIGNAL(rangeChanged(QCPRange)), plot.xAxis2, SLOT(setRange(QCPRange)));
     connect(plot.yAxis, SIGNAL(rangeChanged(QCPRange)), plot.yAxis2, SLOT(setRange(QCPRange)));
     // pass data points to graphs:
     plot.graph(0)->setData(x, y0);
     plot.graph(1)->setData(x, y1);
     // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
     plot.graph(0)->rescaleAxes();
     // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
     plot.graph(1)->rescaleAxes(true);
     // Note: we could have also just called customPlot->rescaleAxes(); instead
     // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
     plot.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
 }

 // Choose the project and main work logic
 void WorkWindow::on_actionOpen_project_triggered() {
     chooseTheProject->setModal(true);
     chooseTheProject->exec();
     drawPlots(project);
     if (chooseTheProject->isProjectChoosen()) {
         project = chooseTheProject->getProjectName();
         drawPlots(project);
     }
 }

 // Log out ability to user, he can change his level
 void WorkWindow::on_actionLog_out_triggered() {

 }

}
