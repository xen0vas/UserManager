/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *menuReload;
    QAction *menuConfiguration;
    QAction *menuLanguage;
    QAction *menuBackup;
    QAction *menuAddUser;
    QAction *menuDeleteUser;
    QAction *menuEditUser;
    QAction *menuSetPassword;
    QAction *menuAddGroup;
    QAction *menuDeleteGroup;
    QAction *menuQuit;
    QAction *menuAboutUserManager;
    QAction *menuAbout_Qt;
    QAction *menuEditGroup;
    QAction *menuDiskUsage;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QToolButton *reloadBtn;
    QToolButton *addUserBtn;
    QToolButton *delUserBtn;
    QToolButton *searchUserBtn;
    QToolButton *searchGroupBtn;
    QToolButton *editBtn;
    QToolButton *delGroupBtn;
    QToolButton *addGroupBtn;
    QToolButton *editGroupBtn;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *usersTab;
    QGridLayout *gridLayout_2;
    QTreeView *userTreeView;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *folderSizeCheckBox;
    QGroupBox *userDetails;
    QGridLayout *gridLayout_10;
    QLabel *loginNameLabel_2;
    QLineEdit *loginNameEdit;
    QLineEdit *realNameEdit;
    QLabel *realNameLabel;
    QLabel *UIDLabel;
    QLineEdit *UIDEdit;
    QLineEdit *priGroupEdit;
    QLabel *statusLabel;
    QLineEdit *statusEdit;
    QLabel *priGrouplabel;
    QLabel *secGroupLabel;
    QLineEdit *secGroupEdit;
    QWidget *groupsTab;
    QGridLayout *gridLayout_11;
    QTreeView *groupTreeView;
    QLabel *membersLabel;
    QTreeView *membersTree;
    QSpacerItem *horizontalSpacer;
    QPushButton *close_app;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFIile;
    QMenu *menuUser;
    QMenu *menuGroup;
    QMenu *menuSettings;
    QMenu *menu_Help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(925, 750);
        QPalette palette;
        QBrush brush(QColor(229, 229, 229, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        MainWindow->setPalette(palette);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/UserManager.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        menuReload = new QAction(MainWindow);
        menuReload->setObjectName(QStringLiteral("menuReload"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuReload->setIcon(icon1);
        menuConfiguration = new QAction(MainWindow);
        menuConfiguration->setObjectName(QStringLiteral("menuConfiguration"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuConfiguration->setIcon(icon2);
        menuLanguage = new QAction(MainWindow);
        menuLanguage->setObjectName(QStringLiteral("menuLanguage"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/language.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuLanguage->setIcon(icon3);
        menuBackup = new QAction(MainWindow);
        menuBackup->setObjectName(QStringLiteral("menuBackup"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/images/backup.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuBackup->setIcon(icon4);
        menuAddUser = new QAction(MainWindow);
        menuAddUser->setObjectName(QStringLiteral("menuAddUser"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/images/user_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAddUser->setIcon(icon5);
        menuDeleteUser = new QAction(MainWindow);
        menuDeleteUser->setObjectName(QStringLiteral("menuDeleteUser"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/images/user_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDeleteUser->setIcon(icon6);
        menuEditUser = new QAction(MainWindow);
        menuEditUser->setObjectName(QStringLiteral("menuEditUser"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/images/editUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuEditUser->setIcon(icon7);
        menuSetPassword = new QAction(MainWindow);
        menuSetPassword->setObjectName(QStringLiteral("menuSetPassword"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/prefix1/images/keys.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuSetPassword->setIcon(icon8);
        menuAddGroup = new QAction(MainWindow);
        menuAddGroup->setObjectName(QStringLiteral("menuAddGroup"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/prefix1/images/group_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAddGroup->setIcon(icon9);
        menuDeleteGroup = new QAction(MainWindow);
        menuDeleteGroup->setObjectName(QStringLiteral("menuDeleteGroup"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/prefix1/images/group_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDeleteGroup->setIcon(icon10);
        menuQuit = new QAction(MainWindow);
        menuQuit->setObjectName(QStringLiteral("menuQuit"));
        QIcon icon11;
        icon11.addFile(QStringLiteral("../resources/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuQuit->setIcon(icon11);
        menuAboutUserManager = new QAction(MainWindow);
        menuAboutUserManager->setObjectName(QStringLiteral("menuAboutUserManager"));
        menuAboutUserManager->setIcon(icon);
        menuAbout_Qt = new QAction(MainWindow);
        menuAbout_Qt->setObjectName(QStringLiteral("menuAbout_Qt"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/prefix1/images/qt.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAbout_Qt->setIcon(icon12);
        menuEditGroup = new QAction(MainWindow);
        menuEditGroup->setObjectName(QStringLiteral("menuEditGroup"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/new/prefix1/images/editGroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuEditGroup->setIcon(icon13);
        menuDiskUsage = new QAction(MainWindow);
        menuDiskUsage->setObjectName(QStringLiteral("menuDiskUsage"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/new/prefix1/images/storage.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDiskUsage->setIcon(icon14);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        reloadBtn = new QToolButton(groupBox);
        reloadBtn->setObjectName(QStringLiteral("reloadBtn"));
        reloadBtn->setGeometry(QRect(0, 0, 51, 41));
        reloadBtn->setIcon(icon1);
        reloadBtn->setIconSize(QSize(60, 60));
        reloadBtn->setAutoRaise(false);
        reloadBtn->setArrowType(Qt::NoArrow);
        addUserBtn = new QToolButton(groupBox);
        addUserBtn->setObjectName(QStringLiteral("addUserBtn"));
        addUserBtn->setGeometry(QRect(50, 0, 51, 41));
        addUserBtn->setAutoFillBackground(false);
        addUserBtn->setIcon(icon5);
        addUserBtn->setIconSize(QSize(60, 60));
        delUserBtn = new QToolButton(groupBox);
        delUserBtn->setObjectName(QStringLiteral("delUserBtn"));
        delUserBtn->setGeometry(QRect(100, 0, 51, 41));
        delUserBtn->setAutoFillBackground(false);
        delUserBtn->setIcon(icon6);
        delUserBtn->setIconSize(QSize(60, 60));
        searchUserBtn = new QToolButton(groupBox);
        searchUserBtn->setObjectName(QStringLiteral("searchUserBtn"));
        searchUserBtn->setGeometry(QRect(150, 0, 51, 41));
        searchUserBtn->setAutoFillBackground(false);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/new/prefix1/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchUserBtn->setIcon(icon15);
        searchUserBtn->setIconSize(QSize(60, 60));
        searchGroupBtn = new QToolButton(groupBox);
        searchGroupBtn->setObjectName(QStringLiteral("searchGroupBtn"));
        searchGroupBtn->setGeometry(QRect(380, 0, 51, 41));
        searchGroupBtn->setAutoFillBackground(false);
        searchGroupBtn->setIcon(icon15);
        searchGroupBtn->setIconSize(QSize(60, 60));
        editBtn = new QToolButton(groupBox);
        editBtn->setObjectName(QStringLiteral("editBtn"));
        editBtn->setGeometry(QRect(200, 0, 41, 41));
        editBtn->setIcon(icon7);
        editBtn->setIconSize(QSize(60, 60));
        delGroupBtn = new QToolButton(groupBox);
        delGroupBtn->setObjectName(QStringLiteral("delGroupBtn"));
        delGroupBtn->setGeometry(QRect(330, 0, 51, 41));
        delGroupBtn->setIcon(icon10);
        delGroupBtn->setIconSize(QSize(60, 60));
        addGroupBtn = new QToolButton(groupBox);
        addGroupBtn->setObjectName(QStringLiteral("addGroupBtn"));
        addGroupBtn->setGeometry(QRect(280, 0, 51, 41));
        addGroupBtn->setIcon(icon9);
        addGroupBtn->setIconSize(QSize(60, 60));
        editGroupBtn = new QToolButton(groupBox);
        editGroupBtn->setObjectName(QStringLiteral("editGroupBtn"));
        editGroupBtn->setEnabled(false);
        editGroupBtn->setGeometry(QRect(240, 0, 41, 41));
        editGroupBtn->setIcon(icon13);
        editGroupBtn->setIconSize(QSize(60, 60));

        gridLayout->addWidget(groupBox, 0, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 4, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setAcceptDrops(true);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(20, 20));
        usersTab = new QWidget();
        usersTab->setObjectName(QStringLiteral("usersTab"));
        gridLayout_2 = new QGridLayout(usersTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        userTreeView = new QTreeView(usersTab);
        userTreeView->setObjectName(QStringLiteral("userTreeView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userTreeView->sizePolicy().hasHeightForWidth());
        userTreeView->setSizePolicy(sizePolicy);
        userTreeView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        userTreeView->setContextMenuPolicy(Qt::DefaultContextMenu);
        userTreeView->setAcceptDrops(true);
        userTreeView->setAutoFillBackground(true);
        userTreeView->setStyleSheet(QStringLiteral(""));
        userTreeView->setLineWidth(0);
        userTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userTreeView->setTabKeyNavigation(true);
        userTreeView->setAlternatingRowColors(true);
        userTreeView->setIconSize(QSize(0, 0));
        userTreeView->setRootIsDecorated(false);
        userTreeView->setSortingEnabled(true);
        userTreeView->setAnimated(true);
        userTreeView->setAllColumnsShowFocus(true);
        userTreeView->setWordWrap(true);

        gridLayout_2->addWidget(userTreeView, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(697, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        folderSizeCheckBox = new QCheckBox(usersTab);
        folderSizeCheckBox->setObjectName(QStringLiteral("folderSizeCheckBox"));
        folderSizeCheckBox->setAutoFillBackground(false);
        folderSizeCheckBox->setIcon(icon14);
        folderSizeCheckBox->setIconSize(QSize(20, 20));
        folderSizeCheckBox->setTristate(false);

        gridLayout_2->addWidget(folderSizeCheckBox, 1, 1, 1, 1);

        userDetails = new QGroupBox(usersTab);
        userDetails->setObjectName(QStringLiteral("userDetails"));
        userDetails->setEnabled(true);
        userDetails->setAutoFillBackground(false);
        userDetails->setAlignment(Qt::AlignCenter);
        userDetails->setFlat(false);
        userDetails->setCheckable(false);
        userDetails->setChecked(false);
        gridLayout_10 = new QGridLayout(userDetails);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        loginNameLabel_2 = new QLabel(userDetails);
        loginNameLabel_2->setObjectName(QStringLiteral("loginNameLabel_2"));
        loginNameLabel_2->setFrameShape(QFrame::NoFrame);
        loginNameLabel_2->setFrameShadow(QFrame::Raised);
        loginNameLabel_2->setTextFormat(Qt::AutoText);
        loginNameLabel_2->setScaledContents(false);
        loginNameLabel_2->setWordWrap(true);

        gridLayout_10->addWidget(loginNameLabel_2, 0, 0, 1, 1);

        loginNameEdit = new QLineEdit(userDetails);
        loginNameEdit->setObjectName(QStringLiteral("loginNameEdit"));
        loginNameEdit->setEnabled(true);
        loginNameEdit->setCursor(QCursor(Qt::ArrowCursor));
        loginNameEdit->setReadOnly(true);

        gridLayout_10->addWidget(loginNameEdit, 0, 1, 1, 1);

        realNameEdit = new QLineEdit(userDetails);
        realNameEdit->setObjectName(QStringLiteral("realNameEdit"));
        realNameEdit->setEnabled(true);
        realNameEdit->setBaseSize(QSize(0, 0));
        realNameEdit->setCursor(QCursor(Qt::ArrowCursor));
        realNameEdit->setReadOnly(true);

        gridLayout_10->addWidget(realNameEdit, 0, 3, 1, 1);

        realNameLabel = new QLabel(userDetails);
        realNameLabel->setObjectName(QStringLiteral("realNameLabel"));
        realNameLabel->setFrameShape(QFrame::NoFrame);
        realNameLabel->setFrameShadow(QFrame::Raised);
        realNameLabel->setTextFormat(Qt::AutoText);
        realNameLabel->setScaledContents(false);
        realNameLabel->setWordWrap(true);

        gridLayout_10->addWidget(realNameLabel, 0, 2, 1, 1);

        UIDLabel = new QLabel(userDetails);
        UIDLabel->setObjectName(QStringLiteral("UIDLabel"));
        UIDLabel->setFrameShape(QFrame::NoFrame);
        UIDLabel->setFrameShadow(QFrame::Raised);
        UIDLabel->setTextFormat(Qt::AutoText);
        UIDLabel->setScaledContents(false);
        UIDLabel->setWordWrap(true);

        gridLayout_10->addWidget(UIDLabel, 1, 0, 1, 1);

        UIDEdit = new QLineEdit(userDetails);
        UIDEdit->setObjectName(QStringLiteral("UIDEdit"));
        UIDEdit->setEnabled(true);
        UIDEdit->setCursor(QCursor(Qt::ArrowCursor));
        UIDEdit->setAutoFillBackground(false);
        UIDEdit->setFrame(true);
        UIDEdit->setReadOnly(true);

        gridLayout_10->addWidget(UIDEdit, 1, 1, 1, 1);

        priGroupEdit = new QLineEdit(userDetails);
        priGroupEdit->setObjectName(QStringLiteral("priGroupEdit"));
        priGroupEdit->setEnabled(true);
        priGroupEdit->setCursor(QCursor(Qt::ArrowCursor));
        priGroupEdit->setReadOnly(true);

        gridLayout_10->addWidget(priGroupEdit, 2, 1, 1, 1);

        statusLabel = new QLabel(userDetails);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setFrameShape(QFrame::NoFrame);
        statusLabel->setFrameShadow(QFrame::Raised);
        statusLabel->setTextFormat(Qt::AutoText);
        statusLabel->setScaledContents(false);
        statusLabel->setWordWrap(true);

        gridLayout_10->addWidget(statusLabel, 1, 2, 1, 1);

        statusEdit = new QLineEdit(userDetails);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));
        statusEdit->setEnabled(true);
        statusEdit->setCursor(QCursor(Qt::ArrowCursor));
        statusEdit->setReadOnly(true);

        gridLayout_10->addWidget(statusEdit, 1, 3, 1, 1);

        priGrouplabel = new QLabel(userDetails);
        priGrouplabel->setObjectName(QStringLiteral("priGrouplabel"));
        priGrouplabel->setFrameShape(QFrame::NoFrame);
        priGrouplabel->setFrameShadow(QFrame::Raised);
        priGrouplabel->setTextFormat(Qt::AutoText);
        priGrouplabel->setScaledContents(false);
        priGrouplabel->setWordWrap(true);

        gridLayout_10->addWidget(priGrouplabel, 2, 0, 1, 1);

        secGroupLabel = new QLabel(userDetails);
        secGroupLabel->setObjectName(QStringLiteral("secGroupLabel"));
        secGroupLabel->setFrameShape(QFrame::NoFrame);
        secGroupLabel->setFrameShadow(QFrame::Raised);
        secGroupLabel->setTextFormat(Qt::AutoText);
        secGroupLabel->setScaledContents(false);
        secGroupLabel->setWordWrap(true);

        gridLayout_10->addWidget(secGroupLabel, 2, 2, 1, 1);

        secGroupEdit = new QLineEdit(userDetails);
        secGroupEdit->setObjectName(QStringLiteral("secGroupEdit"));
        secGroupEdit->setEnabled(true);
        secGroupEdit->setCursor(QCursor(Qt::ArrowCursor));
        secGroupEdit->setReadOnly(true);

        gridLayout_10->addWidget(secGroupEdit, 2, 3, 1, 1);


        gridLayout_2->addWidget(userDetails, 2, 0, 1, 2);

        tabWidget->addTab(usersTab, QString());
        groupsTab = new QWidget();
        groupsTab->setObjectName(QStringLiteral("groupsTab"));
        gridLayout_11 = new QGridLayout(groupsTab);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupTreeView = new QTreeView(groupsTab);
        groupTreeView->setObjectName(QStringLiteral("groupTreeView"));
        groupTreeView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        groupTreeView->setMouseTracking(false);
        groupTreeView->setAcceptDrops(true);
        groupTreeView->setAutoFillBackground(true);
        groupTreeView->setLineWidth(0);
        groupTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        groupTreeView->setTabKeyNavigation(true);
        groupTreeView->setAlternatingRowColors(true);
        groupTreeView->setRootIsDecorated(false);
        groupTreeView->setSortingEnabled(true);
        groupTreeView->setAnimated(true);
        groupTreeView->setAllColumnsShowFocus(true);
        groupTreeView->setWordWrap(true);

        gridLayout_11->addWidget(groupTreeView, 0, 0, 1, 1);

        membersLabel = new QLabel(groupsTab);
        membersLabel->setObjectName(QStringLiteral("membersLabel"));

        gridLayout_11->addWidget(membersLabel, 1, 0, 1, 1);

        membersTree = new QTreeView(groupsTab);
        membersTree->setObjectName(QStringLiteral("membersTree"));
        membersTree->setEnabled(true);
        membersTree->setAutoFillBackground(true);
        membersTree->setFrameShadow(QFrame::Sunken);
        membersTree->setEditTriggers(QAbstractItemView::NoEditTriggers);
        membersTree->setAlternatingRowColors(true);
        membersTree->setRootIsDecorated(false);
        membersTree->setSortingEnabled(true);
        membersTree->setAnimated(true);
        membersTree->setWordWrap(true);

        gridLayout_11->addWidget(membersTree, 2, 0, 1, 1);

        tabWidget->addTab(groupsTab, QString());

        gridLayout->addWidget(tabWidget, 1, 1, 1, 3);

        horizontalSpacer = new QSpacerItem(381, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        close_app = new QPushButton(centralwidget);
        close_app->setObjectName(QStringLiteral("close_app"));
        close_app->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(close_app->sizePolicy().hasHeightForWidth());
        close_app->setSizePolicy(sizePolicy1);
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_app->setIcon(icon16);

        gridLayout->addWidget(close_app, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(381, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 925, 27));
        menuFIile = new QMenu(menubar);
        menuFIile->setObjectName(QStringLiteral("menuFIile"));
        menuUser = new QMenu(menubar);
        menuUser->setObjectName(QStringLiteral("menuUser"));
        menuGroup = new QMenu(menubar);
        menuGroup->setObjectName(QStringLiteral("menuGroup"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFIile->menuAction());
        menubar->addAction(menuUser->menuAction());
        menubar->addAction(menuGroup->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menuFIile->addAction(menuReload);
        menuFIile->addSeparator();
        menuFIile->addAction(menuQuit);
        menuUser->addAction(menuAddUser);
        menuUser->addAction(menuDeleteUser);
        menuUser->addAction(menuEditUser);
        menuUser->addSeparator();
        menuUser->addAction(menuSetPassword);
        menuUser->addAction(menuDiskUsage);
        menuGroup->addAction(menuAddGroup);
        menuGroup->addAction(menuDeleteGroup);
        menuGroup->addAction(menuEditGroup);
        menuSettings->addAction(menuConfiguration);
        menuSettings->addAction(menuBackup);
        menu_Help->addAction(menuAbout_Qt);
        menu_Help->addAction(menuAboutUserManager);

        retranslateUi(MainWindow);
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), loginNameEdit, SLOT(clear()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), UIDEdit, SLOT(clear()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), priGroupEdit, SLOT(clear()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), realNameEdit, SLOT(clear()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), statusEdit, SLOT(clear()));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), secGroupEdit, SLOT(clear()));
        QObject::connect(close_app, SIGNAL(clicked()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "User Manager", Q_NULLPTR));
        menuReload->setText(QApplication::translate("MainWindow", "&Reload", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        menuReload->setStatusTip(QApplication::translate("MainWindow", "Exit Program", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        menuConfiguration->setText(QApplication::translate("MainWindow", "&Configuration...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        menuConfiguration->setStatusTip(QApplication::translate("MainWindow", "UserManager Settings", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        menuLanguage->setText(QApplication::translate("MainWindow", "Language", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        menuLanguage->setStatusTip(QApplication::translate("MainWindow", "Change Language", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        menuBackup->setText(QApplication::translate("MainWindow", "Create Backup", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        menuBackup->setStatusTip(QApplication::translate("MainWindow", "Backup system files", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        menuAddUser->setText(QApplication::translate("MainWindow", "&Add...", Q_NULLPTR));
        menuDeleteUser->setText(QApplication::translate("MainWindow", "&Delete...", Q_NULLPTR));
        menuEditUser->setText(QApplication::translate("MainWindow", "&Edit...", Q_NULLPTR));
        menuSetPassword->setText(QApplication::translate("MainWindow", "&Set Pass&word...", Q_NULLPTR));
        menuAddGroup->setText(QApplication::translate("MainWindow", "&Add...", Q_NULLPTR));
        menuDeleteGroup->setText(QApplication::translate("MainWindow", "&Delete...", Q_NULLPTR));
        menuQuit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        menuAboutUserManager->setText(QApplication::translate("MainWindow", "&About User&Manager", Q_NULLPTR));
        menuAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        menuEditGroup->setText(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuDiskUsage->setText(QApplication::translate("MainWindow", "DIsk Usage", Q_NULLPTR));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        reloadBtn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        reloadBtn->setStatusTip(QApplication::translate("MainWindow", "Reload Lists", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        reloadBtn->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        reloadBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        addUserBtn->setStatusTip(QApplication::translate("MainWindow", "Add New User", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        addUserBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        delUserBtn->setStatusTip(QApplication::translate("MainWindow", "Delete User", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        delUserBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        searchUserBtn->setStatusTip(QApplication::translate("MainWindow", "Search User", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        searchUserBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        searchGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Search Group", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        searchGroupBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        editBtn->setStatusTip(QApplication::translate("MainWindow", "Edit User", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        editBtn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        delGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Delete Group", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        delGroupBtn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        addGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Add New Group", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        addGroupBtn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        editGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Edit Group", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        editGroupBtn->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        tabWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        folderSizeCheckBox->setText(QApplication::translate("MainWindow", "Show Usage", Q_NULLPTR));
        userDetails->setTitle(QApplication::translate("MainWindow", "Details:", Q_NULLPTR));
        loginNameLabel_2->setText(QApplication::translate("MainWindow", "Login Name:", Q_NULLPTR));
        realNameLabel->setText(QApplication::translate("MainWindow", "Real Name:", Q_NULLPTR));
        UIDLabel->setText(QApplication::translate("MainWindow", "UID:", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("MainWindow", "Status:", Q_NULLPTR));
        priGrouplabel->setText(QApplication::translate("MainWindow", "Primary Group:", Q_NULLPTR));
        secGroupLabel->setText(QApplication::translate("MainWindow", "Secondary Group(s):", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(usersTab), QApplication::translate("MainWindow", "Users", Q_NULLPTR));
        membersLabel->setText(QApplication::translate("MainWindow", "Group Members", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(groupsTab), QApplication::translate("MainWindow", "Groups", Q_NULLPTR));
        close_app->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        menuFIile->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuUser->setTitle(QApplication::translate("MainWindow", "&User", Q_NULLPTR));
        menuGroup->setTitle(QApplication::translate("MainWindow", "&Group", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "&Settings", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
