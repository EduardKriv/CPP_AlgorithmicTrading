#ifndef VIEW_H
#define VIEW_H

#include <QDate>
#include <QFileDialog>
#include <QMainWindow>
#include <QWheelEvent>

#include "controller/controller.h"
#include "view/graphic.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace alg {
class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(alg::Controller* ctrl, QWidget* parent = nullptr);
  ~View();

 private slots:
  void on_pb_calc_by_date_clicked();
  void on_pb_approximate_clicked();
  void on_pb_interpolate_clicked();
  void on_pb_load_clicked();

  void SetDateRange(int = 0);
  void SetEnabledDraw(bool);

 private:
  Ui::View* ui;
  Controller* ctrl_;
  Graphic* graphic_;

  Controller::point_t ConvertDateToQdate(const alg::Loader::Data&);

 signals:
  void DrawPoints(const Controller::point_t&, QString&);
  void Draw(const Controller::point_t&, const QString& = "");
};
}  // namespace alg
#endif  // VIEW_H
