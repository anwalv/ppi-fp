#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    addSampleData();
}

MainWindow::~MainWindow()
{
}

void MainWindow::addToFavorites(const QString &item)
{
    for (int i = 0; i < favoritesList->count(); i++) {
        if (favoritesList->item(i)->text() == item)
            return;
    }
    favoritesList->addItem(item);
}

void MainWindow::setupUI()
{
    setWindowTitle("Меню ресторану");
    setMinimumSize(400, 600);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    tabWidget = new QTabWidget();

    menuTab = new QWidget();
    setupMenuTab();
    tabWidget->addTab(menuTab, "Меню");

    favoritesTab = new QWidget();
    setupFavoritesTab();
    tabWidget->addTab(favoritesTab, "Улюблені");

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(tabWidget);
}

void MainWindow::setupMenuTab()
{
    QVBoxLayout *menuLayout = new QVBoxLayout(menuTab);

    QLabel *title = new QLabel("Наше меню");
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    menuLayout->addWidget(title);

    QHBoxLayout *categoryLayout = new QHBoxLayout();
    QPushButton *burgersBtn = new QPushButton("Бургери");
    QPushButton *drinksBtn = new QPushButton("Напої");
    burgersBtn->setMinimumHeight(50);
    drinksBtn->setMinimumHeight(50);
    categoryLayout->addWidget(burgersBtn);
    categoryLayout->addWidget(drinksBtn);
    menuLayout->addLayout(categoryLayout);

    scrollArea = new QScrollArea(menuTab); // << прив'язаний до menuTab
    scrollArea->setWidgetResizable(true);

    burgersWidget = createBurgersWidget();
    drinksWidget = createDrinksWidget();
    scrollArea->setWidget(burgersWidget);
    menuLayout->addWidget(scrollArea);

    connect(burgersBtn, &QPushButton::clicked, [=]() {
        scrollArea->setWidget(burgersWidget);
    });

    connect(drinksBtn, &QPushButton::clicked, [=]() {
        scrollArea->setWidget(drinksWidget);
    });
}

void MainWindow::setupFavoritesTab()
{
    QVBoxLayout *favLayout = new QVBoxLayout(favoritesTab);

    QLabel *title = new QLabel("Улюблені страви");
    QFont titleFont;
    titleFont.setPointSize(18);
    titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    favLayout->addWidget(title);

    favoritesList = new QListWidget(favoritesTab);
    favoritesList->setMinimumHeight(400);
    favLayout->addWidget(favoritesList);
}

QWidget* MainWindow::createBurgersWidget()
{
    QWidget *widget = new QWidget(menuTab); // << додано parent
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QStringList burgers = {
        "Класичний бургер - 150 грн",
        "Чізбургер - 170 грн",
        "Біг Мак - 190 грн"
    };

    for (const QString &burger : burgers) {
        QWidget *itemWidget = new QWidget(widget);
        QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);

        QLabel *label = new QLabel(burger);
        label->setMinimumHeight(40);

        QPushButton *favBtn = new QPushButton("♥");
        favBtn->setMaximumWidth(50);
        favBtn->setStyleSheet("QPushButton { background-color: #ff6b6b; color: white; border: none; border-radius: 15px; }");

        itemLayout->addWidget(label);
        itemLayout->addWidget(favBtn);
        layout->addWidget(itemWidget);

        connect(favBtn, &QPushButton::clicked, [=]() {
            addToFavorites(burger);
        });
    }

    return widget;
}

QWidget* MainWindow::createDrinksWidget()
{
    QWidget *widget = new QWidget(menuTab); // << додано parent
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QStringList drinks = {
        "Кока-кола - 50 грн",
        "Апельсиновий сік - 60 грн",
        "Кава - 40 грн"
    };

    for (const QString &drink : drinks) {
        QWidget *itemWidget = new QWidget(widget);
        QHBoxLayout *itemLayout = new QHBoxLayout(itemWidget);

        QLabel *label = new QLabel(drink);
        label->setMinimumHeight(40);

        QPushButton *favBtn = new QPushButton("♥");
        favBtn->setMaximumWidth(50);
        favBtn->setStyleSheet("QPushButton { background-color: #ff6b6b; color: white; border: none; border-radius: 15px; }");

        itemLayout->addWidget(label);
        itemLayout->addWidget(favBtn);
        layout->addWidget(itemWidget);

        connect(favBtn, &QPushButton::clicked, [=]() {
            addToFavorites(drink);
        });
    }

    return widget;
}

void MainWindow::addSampleData()
{
    // Тестові дані за потребою
}
