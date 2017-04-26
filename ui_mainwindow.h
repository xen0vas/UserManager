/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
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
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/UserManager.gif"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        menuReload = new QAction(MainWindow);
        menuReload->setObjectName(QString::fromUtf8("menuReload"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuReload->setIcon(icon1);
        menuConfiguration = new QAction(MainWindow);
        menuConfiguration->setObjectName(QString::fromUtf8("menuConfiguration"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuConfiguration->setIcon(icon2);
        menuLanguage = new QAction(MainWindow);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/language.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuLanguage->setIcon(icon3);
        menuBackup = new QAction(MainWindow);
        menuBackup->setObjectName(QString::fromUtf8("menuBackup"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/backup.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuBackup->setIcon(icon4);
        menuAddUser = new QAction(MainWindow);
        menuAddUser->setObjectName(QString::fromUtf8("menuAddUser"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/user_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAddUser->setIcon(icon5);
        menuDeleteUser = new QAction(MainWindow);
        menuDeleteUser->setObjectName(QString::fromUtf8("menuDeleteUser"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/user_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDeleteUser->setIcon(icon6);
        menuEditUser = new QAction(MainWindow);
        menuEditUser->setObjectName(QString::fromUtf8("menuEditUser"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/editUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuEditUser->setIcon(icon7);
        menuSetPassword = new QAction(MainWindow);
        menuSetPassword->setObjectName(QString::fromUtf8("menuSetPassword"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/images/keys.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuSetPassword->setIcon(icon8);
        menuAddGroup = new QAction(MainWindow);
        menuAddGroup->setObjectName(QString::fromUtf8("menuAddGroup"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/images/group_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAddGroup->setIcon(icon9);
        menuDeleteGroup = new QAction(MainWindow);
        menuDeleteGroup->setObjectName(QString::fromUtf8("menuDeleteGroup"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/images/group_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDeleteGroup->setIcon(icon10);
        menuQuit = new QAction(MainWindow);
        menuQuit->setObjectName(QString::fromUtf8("menuQuit"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../resources/images/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuQuit->setIcon(icon11);
        menuAboutUserManager = new QAction(MainWindow);
        menuAboutUserManager->setObjectName(QString::fromUtf8("menuAboutUserManager"));
        menuAboutUserManager->setIcon(icon);
        menuAbout_Qt = new QAction(MainWindow);
        menuAbout_Qt->setObjectName(QString::fromUtf8("menuAbout_Qt"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/images/qt.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuAbout_Qt->setIcon(icon12);
        menuEditGroup = new QAction(MainWindow);
        menuEditGroup->setObjectName(QString::fromUtf8("menuEditGroup"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/images/editGroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuEditGroup->setIcon(icon13);
        menuDiskUsage = new QAction(MainWindow);
        menuDiskUsage->setObjectName(QString::fromUtf8("menuDiskUsage"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/images/storage.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuDiskUsage->setIcon(icon14);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        reloadBtn = new QToolButton(groupBox);
        reloadBtn->setObjectName(QString::fromUtf8("reloadBtn"));
        reloadBtn->setGeometry(QRect(0, 0, 51, 41));
        reloadBtn->setIcon(icon1);
        reloadBtn->setIconSize(QSize(60, 60));
        reloadBtn->setAutoRaise(false);
        reloadBtn->setArrowType(Qt::NoArrow);
        addUserBtn = new QToolButton(groupBox);
        addUserBtn->setObjectName(QString::fromUtf8("addUserBtn"));
        addUserBtn->setGeometry(QRect(50, 0, 51, 41));
        addUserBtn->setAutoFillBackground(false);
        addUserBtn->setIcon(icon5);
        addUserBtn->setIconSize(QSize(60, 60));
        delUserBtn = new QToolButton(groupBox);
        delUserBtn->setObjectName(QString::fromUtf8("delUserBtn"));
        delUserBtn->setGeometry(QRect(100, 0, 51, 41));
        delUserBtn->setAutoFillBackground(false);
        delUserBtn->setIcon(icon6);
        delUserBtn->setIconSize(QSize(60, 60));
        searchUserBtn = new QToolButton(groupBox);
        searchUserBtn->setObjectName(QString::fromUtf8("searchUserBtn"));
        searchUserBtn->setGeometry(QRect(150, 0, 51, 41));
        searchUserBtn->setAutoFillBackground(false);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/images/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchUserBtn->setIcon(icon15);
        searchUserBtn->setIconSize(QSize(60, 60));
        searchGroupBtn = new QToolButton(groupBox);
        searchGroupBtn->setObjectName(QString::fromUtf8("searchGroupBtn"));
        searchGroupBtn->setGeometry(QRect(380, 0, 51, 41));
        searchGroupBtn->setAutoFillBackground(false);
        searchGroupBtn->setIcon(icon15);
        searchGroupBtn->setIconSize(QSize(60, 60));
        editBtn = new QToolButton(groupBox);
        editBtn->setObjectName(QString::fromUtf8("editBtn"));
        editBtn->setGeometry(QRect(200, 0, 41, 41));
        editBtn->setIcon(icon7);
        editBtn->setIconSize(QSize(60, 60));
        delGroupBtn = new QToolButton(groupBox);
        delGroupBtn->setObjectName(QString::fromUtf8("delGroupBtn"));
        delGroupBtn->setGeometry(QRect(330, 0, 51, 41));
        delGroupBtn->setIcon(icon10);
        delGroupBtn->setIconSize(QSize(60, 60));
        addGroupBtn = new QToolButton(groupBox);
        addGroupBtn->setObjectName(QString::fromUtf8("addGroupBtn"));
        addGroupBtn->setGeometry(QRect(280, 0, 51, 41));
        addGroupBtn->setIcon(icon9);
        addGroupBtn->setIconSize(QSize(60, 60));
        editGroupBtn = new QToolButton(groupBox);
        editGroupBtn->setObjectName(QString::fromUtf8("editGroupBtn"));
        editGroupBtn->setEnabled(false);
        editGroupBtn->setGeometry(QRect(240, 0, 41, 41));
        editGroupBtn->setIcon(icon13);
        editGroupBtn->setIconSize(QSize(60, 60));

        gridLayout->addWidget(groupBox, 0, 1, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 4, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setAcceptDrops(true);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(20, 20));
        usersTab = new QWidget();
        usersTab->setObjectName(QString::fromUtf8("usersTab"));
        gridLayout_2 = new QGridLayout(usersTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        userTreeView = new QTreeView(usersTab);
        userTreeView->setObjectName(QString::fromUtf8("userTreeView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userTreeView->sizePolicy().hasHeightForWidth());
        userTreeView->setSizePolicy(sizePolicy);
        userTreeView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        userTreeView->setContextMenuPolicy(Qt::DefaultContextMenu);
        userTreeView->setAcceptDrops(true);
        userTreeView->setAutoFillBackground(true);
        userTreeView->setStyleSheet(QString::fromUtf8(""));
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
        folderSizeCheckBox->setObjectName(QString::fromUtf8("folderSizeCheckBox"));
        folderSizeCheckBox->setAutoFillBackground(false);
        folderSizeCheckBox->setIcon(icon14);
        folderSizeCheckBox->setIconSize(QSize(20, 20));
        folderSizeCheckBox->setTristate(false);

        gridLayout_2->addWidget(folderSizeCheckBox, 1, 1, 1, 1);

        userDetails = new QGroupBox(usersTab);
        userDetails->setObjectName(QString::fromUtf8("userDetails"));
        userDetails->setEnabled(true);
        userDetails->setAutoFillBackground(false);
        userDetails->setAlignment(Qt::AlignCenter);
        userDetails->setFlat(false);
        userDetails->setCheckable(false);
        userDetails->setChecked(false);
        gridLayout_10 = new QGridLayout(userDetails);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        loginNameLabel_2 = new QLabel(userDetails);
        loginNameLabel_2->setObjectName(QString::fromUtf8("loginNameLabel_2"));
        loginNameLabel_2->setFrameShape(QFrame::NoFrame);
        loginNameLabel_2->setFrameShadow(QFrame::Raised);
        loginNameLabel_2->setTextFormat(Qt::AutoText);
        loginNameLabel_2->setScaledContents(false);
        loginNameLabel_2->setWordWrap(true);

        gridLayout_10->addWidget(loginNameLabel_2, 0, 0, 1, 1);

        loginNameEdit = new QLineEdit(userDetails);
        loginNameEdit->setObjectName(QString::fromUtf8("loginNameEdit"));
        loginNameEdit->setEnabled(true);
        loginNameEdit->setCursor(QCursor(Qt::ArrowCursor));
        loginNameEdit->setReadOnly(true);

        gridLayout_10->addWidget(loginNameEdit, 0, 1, 1, 1);

        realNameEdit = new QLineEdit(userDetails);
        realNameEdit->setObjectName(QString::fromUtf8("realNameEdit"));
        realNameEdit->setEnabled(true);
        realNameEdit->setBaseSize(QSize(0, 0));
        realNameEdit->setCursor(QCursor(Qt::ArrowCursor));
        realNameEdit->setReadOnly(true);

        gridLayout_10->addWidget(realNameEdit, 0, 3, 1, 1);

        realNameLabel = new QLabel(userDetails);
        realNameLabel->setObjectName(QString::fromUtf8("realNameLabel"));
        realNameLabel->setFrameShape(QFrame::NoFrame);
        realNameLabel->setFrameShadow(QFrame::Raised);
        realNameLabel->setTextFormat(Qt::AutoText);
        realNameLabel->setScaledContents(false);
        realNameLabel->setWordWrap(true);

        gridLayout_10->addWidget(realNameLabel, 0, 2, 1, 1);

        UIDLabel = new QLabel(userDetails);
        UIDLabel->setObjectName(QString::fromUtf8("UIDLabel"));
        UIDLabel->setFrameShape(QFrame::NoFrame);
        UIDLabel->setFrameShadow(QFrame::Raised);
        UIDLabel->setTextFormat(Qt::AutoText);
        UIDLabel->setScaledContents(false);
        UIDLabel->setWordWrap(true);

        gridLayout_10->addWidget(UIDLabel, 1, 0, 1, 1);

        UIDEdit = new QLineEdit(userDetails);
        UIDEdit->setObjectName(QString::fromUtf8("UIDEdit"));
        UIDEdit->setEnabled(true);
        UIDEdit->setCursor(QCursor(Qt::ArrowCursor));
        UIDEdit->setAutoFillBackground(false);
        UIDEdit->setFrame(true);
        UIDEdit->setReadOnly(true);

        gridLayout_10->addWidget(UIDEdit, 1, 1, 1, 1);

        priGroupEdit = new QLineEdit(userDetails);
        priGroupEdit->setObjectName(QString::fromUtf8("priGroupEdit"));
        priGroupEdit->setEnabled(true);
        priGroupEdit->setCursor(QCursor(Qt::ArrowCursor));
        priGroupEdit->setReadOnly(true);

        gridLayout_10->addWidget(priGroupEdit, 2, 1, 1, 1);

        statusLabel = new QLabel(userDetails);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setFrameShape(QFrame::NoFrame);
        statusLabel->setFrameShadow(QFrame::Raised);
        statusLabel->setTextFormat(Qt::AutoText);
        statusLabel->setScaledContents(false);
        statusLabel->setWordWrap(true);

        gridLayout_10->addWidget(statusLabel, 1, 2, 1, 1);

        statusEdit = new QLineEdit(userDetails);
        statusEdit->setObjectName(QString::fromUtf8("statusEdit"));
        statusEdit->setEnabled(true);
        statusEdit->setCursor(QCursor(Qt::ArrowCursor));
        statusEdit->setReadOnly(true);

        gridLayout_10->addWidget(statusEdit, 1, 3, 1, 1);

        priGrouplabel = new QLabel(userDetails);
        priGrouplabel->setObjectName(QString::fromUtf8("priGrouplabel"));
        priGrouplabel->setFrameShape(QFrame::NoFrame);
        priGrouplabel->setFrameShadow(QFrame::Raised);
        priGrouplabel->setTextFormat(Qt::AutoText);
        priGrouplabel->setScaledContents(false);
        priGrouplabel->setWordWrap(true);

        gridLayout_10->addWidget(priGrouplabel, 2, 0, 1, 1);

        secGroupLabel = new QLabel(userDetails);
        secGroupLabel->setObjectName(QString::fromUtf8("secGroupLabel"));
        secGroupLabel->setFrameShape(QFrame::NoFrame);
        secGroupLabel->setFrameShadow(QFrame::Raised);
        secGroupLabel->setTextFormat(Qt::AutoText);
        secGroupLabel->setScaledContents(false);
        secGroupLabel->setWordWrap(true);

        gridLayout_10->addWidget(secGroupLabel, 2, 2, 1, 1);

        secGroupEdit = new QLineEdit(userDetails);
        secGroupEdit->setObjectName(QString::fromUtf8("secGroupEdit"));
        secGroupEdit->setEnabled(true);
        secGroupEdit->setCursor(QCursor(Qt::ArrowCursor));
        secGroupEdit->setReadOnly(true);

        gridLayout_10->addWidget(secGroupEdit, 2, 3, 1, 1);


        gridLayout_2->addWidget(userDetails, 2, 0, 1, 2);

        tabWidget->addTab(usersTab, QString());
        groupsTab = new QWidget();
        groupsTab->setObjectName(QString::fromUtf8("groupsTab"));
        gridLayout_11 = new QGridLayout(groupsTab);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupTreeView = new QTreeView(groupsTab);
        groupTreeView->setObjectName(QString::fromUtf8("groupTreeView"));
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
        membersLabel->setObjectName(QString::fromUtf8("membersLabel"));

        gridLayout_11->addWidget(membersLabel, 1, 0, 1, 1);

        membersTree = new QTreeView(groupsTab);
        membersTree->setObjectName(QString::fromUtf8("membersTree"));
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
        close_app->setObjectName(QString::fromUtf8("close_app"));
        close_app->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(close_app->sizePolicy().hasHeightForWidth());
        close_app->setSizePolicy(sizePolicy1);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        close_app->setIcon(icon16);

        gridLayout->addWidget(close_app, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(381, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 925, 27));
        menuFIile = new QMenu(menubar);
        menuFIile->setObjectName(QString::fromUtf8("menuFIile"));
        menuUser = new QMenu(menubar);
        menuUser->setObjectName(QString::fromUtf8("menuUser"));
        menuGroup = new QMenu(menubar);
        menuGroup->setObjectName(QString::fromUtf8("menuGroup"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "User Manager", 0, QApplication::UnicodeUTF8));
        menuReload->setText(QApplication::translate("MainWindow", "&Reload", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        menuReload->setStatusTip(QApplication::translate("MainWindow", "Exit Program", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menuConfiguration->setText(QApplication::translate("MainWindow", "&Configuration...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        menuConfiguration->setStatusTip(QApplication::translate("MainWindow", "UserManager Settings", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menuLanguage->setText(QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        menuLanguage->setStatusTip(QApplication::translate("MainWindow", "Change Language", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menuBackup->setText(QApplication::translate("MainWindow", "Create Backup", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        menuBackup->setStatusTip(QApplication::translate("MainWindow", "Backup system files", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        menuAddUser->setText(QApplication::translate("MainWindow", "&Add...", 0, QApplication::UnicodeUTF8));
        menuDeleteUser->setText(QApplication::translate("MainWindow", "&Delete...", 0, QApplication::UnicodeUTF8));
        menuEditUser->setText(QApplication::translate("MainWindow", "&Edit...", 0, QApplication::UnicodeUTF8));
        menuSetPassword->setText(QApplication::translate("MainWindow", "&Set Pass&word...", 0, QApplication::UnicodeUTF8));
        menuAddGroup->setText(QApplication::translate("MainWindow", "&Add...", 0, QApplication::UnicodeUTF8));
        menuDeleteGroup->setText(QApplication::translate("MainWindow", "&Delete...", 0, QApplication::UnicodeUTF8));
        menuQuit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        menuAboutUserManager->setText(QApplication::translate("MainWindow", "&About User&Manager", 0, QApplication::UnicodeUTF8));
        menuAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        menuEditGroup->setText(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuDiskUsage->setText(QApplication::translate("MainWindow", "DIsk Usage", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        reloadBtn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        reloadBtn->setStatusTip(QApplication::translate("MainWindow", "Reload Lists", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        reloadBtn->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        reloadBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        addUserBtn->setStatusTip(QApplication::translate("MainWindow", "Add New User", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        addUserBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        delUserBtn->setStatusTip(QApplication::translate("MainWindow", "Delete User", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        delUserBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        searchUserBtn->setStatusTip(QApplication::translate("MainWindow", "Search User", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        searchUserBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        searchGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Search Group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        searchGroupBtn->setText(QString());
#ifndef QT_NO_STATUSTIP
        editBtn->setStatusTip(QApplication::translate("MainWindow", "Edit User", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        editBtn->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        delGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Delete Group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        delGroupBtn->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        addGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Add New Group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        addGroupBtn->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        editGroupBtn->setStatusTip(QApplication::translate("MainWindow", "Edit Group", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        editGroupBtn->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tabWidget->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        folderSizeCheckBox->setText(QApplication::translate("MainWindow", "Show Usage", 0, QApplication::UnicodeUTF8));
        userDetails->setTitle(QApplication::translate("MainWindow", "Details:", 0, QApplication::UnicodeUTF8));
        loginNameLabel_2->setText(QApplication::translate("MainWindow", "Login Name:", 0, QApplication::UnicodeUTF8));
        realNameLabel->setText(QApplication::translate("MainWindow", "Real Name:", 0, QApplication::UnicodeUTF8));
        UIDLabel->setText(QApplication::translate("MainWindow", "UID:", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("MainWindow", "Status:", 0, QApplication::UnicodeUTF8));
        priGrouplabel->setText(QApplication::translate("MainWindow", "Primary Group:", 0, QApplication::UnicodeUTF8));
        secGroupLabel->setText(QApplication::translate("MainWindow", "Secondary Group(s):", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(usersTab), QApplication::translate("MainWindow", "Users", 0, QApplication::UnicodeUTF8));
        membersLabel->setText(QApplication::translate("MainWindow", "Group Members", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(groupsTab), QApplication::translate("MainWindow", "Groups", 0, QApplication::UnicodeUTF8));
        close_app->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        menuFIile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuUser->setTitle(QApplication::translate("MainWindow", "&User", 0, QApplication::UnicodeUTF8));
        menuGroup->setTitle(QApplication::translate("MainWindow", "&Group", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "&Settings", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
