//*****************************************************
//
// Dialog which report the earning made with stake over time
// Original coding by Remy5
//

#ifndef roiReportDIALOG_H
#define roiReportDIALOG_H

#include <QDialog>

namespace Ui {
class roiReportDialog;
}

class WalletModel;

class roiReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit roiReportDialog(QWidget *parent = 0);
    ~roiReportDialog();

    void setModel(WalletModel *model);
    void showEvent(QShowEvent* event);

private:
    Ui::roiReportDialog *ui;
    WalletModel *ex_model;

    qint64 nLastReportUpdate;
    bool disablereportupdate;
    bool alreadyConnected;

    void updateroiReport(bool fImmediate);

private slots:
    void updateroiReportTimer();

public slots:
    void updateroiReportbalanceChanged(qint64, qint64, qint64, qint64);
    void updateroiReportNow();
    void updateDisplayUnit(int);
    void CopyAllToClipboard();
};

#endif // roiReportDIALOG_H
