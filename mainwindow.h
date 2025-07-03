#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QListWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTabWidget *tabWidget;
    QWidget *menuTab;
    QWidget *favoritesTab;
    QListWidget *favoritesList;

    QWidget *burgersWidget;
    QWidget *drinksWidget;
    QScrollArea *scrollArea; // << оголошено як член

    void setupUI();
    void setupMenuTab();
    void setupFavoritesTab();
    QWidget* createBurgersWidget();
    QWidget* createDrinksWidget();
    void addToFavorites(const QString &item);
    void addSampleData();
};

#endif // MAINWINDOW_H
