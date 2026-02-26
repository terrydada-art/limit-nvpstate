#pragma once

#include <ui_limitnvpstate.h>
#include <QSystemTrayIcon>
#include <unordered_set>

class limitnvpstate : public QMainWindow {
    Q_OBJECT

public:
    limitnvpstate(QWidget* parent = nullptr);

private:
    Ui::limitnvpstateClass ui;

    void setupProcessRunningTrigger();
    void stopProcessRunningTrigger();
    void setupProcessForegroundTrigger();
    void stopProcessForegroundTrigger();
    void setupUnlimitTrigger();
    void stopUnlimitTrigger();
    void applyPStateLimitState(bool isEnabled);
    void updateToggleButtonText(bool isEnabled);
    void updatePStateLimitStatus(bool isEnabled);
    void createTrayIcon();
    void saveProcessExceptions();
    void getAvailablePStates();

    bool isPStateLimitEnabled = true;
    QSystemTrayIcon* trayIcon = nullptr;

private slots:
    void unlimitTriggerChanged(int index);
    void selectedGPUChanged(int index);
    void selectedPStateChanged(int index);
    void togglePStateLimit();
    void addProcess();
    void exitApp(int exitCode);

protected:
    void closeEvent(QCloseEvent* event) override;
    void changeEvent(QEvent* e) override;
};
