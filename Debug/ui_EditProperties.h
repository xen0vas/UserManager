/********************************************************************************
** Form generated from reading UI file 'EditProperties.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPROPERTIES_H
#define UI_EDITPROPERTIES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditProperties
{
public:
    QGridLayout *gridLayout;
    QPushButton *cancelBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *edit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *LoginName;
    QPushButton *pass;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *uiEdit;
    QLabel *label_5;
    QLineEdit *FullNameEdit;
    QLabel *label_6;
    QComboBox *shellConnect;
    QLabel *label_7;
    QLineEdit *DirEdit;
    QPushButton *browseBtn;
    QLabel *label_10;
    QLineEdit *office1Edit;
    QLabel *label_8;
    QLineEdit *office2Edit;
    QLabel *label_11;
    QLineEdit *addressEdit;
    QLabel *label_12;
    QCheckBox *checkBoxEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *verticalSpacer_15;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *datetime;
    QFrame *line;
    QLabel *label_9;
    QCheckBox *requires_Pass;
    QSpinBox *max;
    QLabel *label_14;
    QSpinBox *warn;
    QLabel *label_15;
    QSpinBox *expire;
    QCheckBox *enforce_Pass;
    QLabel *label_16;
    QSpinBox *min;
    QFrame *line_2;
    QLabel *label_17;
    QSpinBox *days;
    QComboBox *months;
    QSpinBox *years;
    QCheckBox *alway;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_13;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_13;
    QWidget *tab_3;
    QTreeView *userGroups;
    QListWidget *easyList;
    QCheckBox *easyCheckbox;
    QLabel *label;
    QPushButton *makePrimBtn;
    QLabel *primGroupLabel;

    void setupUi(QDialog *EditProperties)
    {
        if (EditProperties->objectName().isEmpty())
            EditProperties->setObjectName(QString::fromUtf8("EditProperties"));
        EditProperties->resize(784, 442);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/editUser.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditProperties->setWindowIcon(icon);
        gridLayout = new QGridLayout(EditProperties);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cancelBtn = new QPushButton(EditProperties);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelBtn->setIcon(icon1);

        gridLayout->addWidget(cancelBtn, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        edit = new QPushButton(EditProperties);
        edit->setObjectName(QString::fromUtf8("edit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        edit->setIcon(icon2);

        gridLayout->addWidget(edit, 2, 2, 1, 1);

        tabWidget = new QTabWidget(EditProperties);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setKerning(true);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        LoginName = new QLabel(tab);
        LoginName->setObjectName(QString::fromUtf8("LoginName"));

        gridLayout_2->addWidget(LoginName, 0, 2, 1, 2);

        pass = new QPushButton(tab);
        pass->setObjectName(QString::fromUtf8("pass"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/keys.png"), QSize(), QIcon::Normal, QIcon::Off);
        pass->setIcon(icon3);

        gridLayout_2->addWidget(pass, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setScaledContents(true);
        label_3->setWordWrap(false);

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        uiEdit = new QLineEdit(tab);
        uiEdit->setObjectName(QString::fromUtf8("uiEdit"));

        gridLayout_2->addWidget(uiEdit, 3, 2, 1, 4);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setScaledContents(true);
        label_5->setWordWrap(false);

        gridLayout_2->addWidget(label_5, 5, 0, 1, 1);

        FullNameEdit = new QLineEdit(tab);
        FullNameEdit->setObjectName(QString::fromUtf8("FullNameEdit"));

        gridLayout_2->addWidget(FullNameEdit, 5, 2, 1, 4);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setScaledContents(true);
        label_6->setWordWrap(false);

        gridLayout_2->addWidget(label_6, 7, 0, 1, 1);

        shellConnect = new QComboBox(tab);
        shellConnect->setObjectName(QString::fromUtf8("shellConnect"));

        gridLayout_2->addWidget(shellConnect, 7, 2, 1, 4);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setScaledContents(true);
        label_7->setWordWrap(false);

        gridLayout_2->addWidget(label_7, 9, 0, 1, 1);

        DirEdit = new QLineEdit(tab);
        DirEdit->setObjectName(QString::fromUtf8("DirEdit"));

        gridLayout_2->addWidget(DirEdit, 9, 2, 1, 3);

        browseBtn = new QPushButton(tab);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));

        gridLayout_2->addWidget(browseBtn, 9, 5, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setScaledContents(true);
        label_10->setWordWrap(false);

        gridLayout_2->addWidget(label_10, 11, 0, 1, 1);

        office1Edit = new QLineEdit(tab);
        office1Edit->setObjectName(QString::fromUtf8("office1Edit"));

        gridLayout_2->addWidget(office1Edit, 11, 2, 1, 4);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setScaledContents(true);
        label_8->setWordWrap(false);

        gridLayout_2->addWidget(label_8, 13, 0, 1, 1);

        office2Edit = new QLineEdit(tab);
        office2Edit->setObjectName(QString::fromUtf8("office2Edit"));

        gridLayout_2->addWidget(office2Edit, 13, 2, 1, 4);

        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setScaledContents(true);
        label_11->setWordWrap(false);

        gridLayout_2->addWidget(label_11, 15, 0, 1, 1);

        addressEdit = new QLineEdit(tab);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));

        gridLayout_2->addWidget(addressEdit, 15, 2, 1, 4);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setScaledContents(true);
        label_12->setWordWrap(true);

        gridLayout_2->addWidget(label_12, 17, 0, 2, 1);

        checkBoxEdit = new QCheckBox(tab);
        checkBoxEdit->setObjectName(QString::fromUtf8("checkBoxEdit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/lock.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkBoxEdit->setIcon(icon4);

        gridLayout_2->addWidget(checkBoxEdit, 17, 2, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 12, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 8, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 14, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 6, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_5, 4, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_6, 10, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_14, 16, 0, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_15, 19, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 3);

        datetime = new QLabel(tab_2);
        datetime->setObjectName(QString::fromUtf8("datetime"));

        gridLayout_3->addWidget(datetime, 0, 3, 1, 3);

        line = new QFrame(tab_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        gridLayout_3->addWidget(line, 1, 0, 1, 6);

        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 2);

        requires_Pass = new QCheckBox(tab_2);
        requires_Pass->setObjectName(QString::fromUtf8("requires_Pass"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(requires_Pass->sizePolicy().hasHeightForWidth());
        requires_Pass->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setStrikeOut(false);
        requires_Pass->setFont(font1);

        gridLayout_3->addWidget(requires_Pass, 3, 0, 1, 1);

        max = new QSpinBox(tab_2);
        max->setObjectName(QString::fromUtf8("max"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(max->sizePolicy().hasHeightForWidth());
        max->setSizePolicy(sizePolicy2);
        max->setLayoutDirection(Qt::LeftToRight);
        max->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        max->setMaximum(99999);
        max->setValue(0);

        gridLayout_3->addWidget(max, 3, 4, 1, 2);

        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 6, 0, 1, 4);

        warn = new QSpinBox(tab_2);
        warn->setObjectName(QString::fromUtf8("warn"));
        warn->setLayoutDirection(Qt::LeftToRight);
        warn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        warn->setKeyboardTracking(false);
        warn->setMaximum(99999);
        warn->setValue(99999);

        gridLayout_3->addWidget(warn, 6, 4, 1, 2);

        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 8, 0, 1, 4);

        expire = new QSpinBox(tab_2);
        expire->setObjectName(QString::fromUtf8("expire"));
        expire->setLayoutDirection(Qt::LeftToRight);
        expire->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        expire->setMinimum(0);
        expire->setMaximum(99999);
        expire->setValue(7);

        gridLayout_3->addWidget(expire, 8, 4, 1, 2);

        enforce_Pass = new QCheckBox(tab_2);
        enforce_Pass->setObjectName(QString::fromUtf8("enforce_Pass"));
        QFont font2;
        font2.setStrikeOut(true);
        font2.setKerning(false);
        enforce_Pass->setFont(font2);

        gridLayout_3->addWidget(enforce_Pass, 10, 0, 1, 1);

        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 10, 1, 1, 3);

        min = new QSpinBox(tab_2);
        min->setObjectName(QString::fromUtf8("min"));
        min->setLayoutDirection(Qt::LeftToRight);
        min->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        min->setMinimum(-1);
        min->setMaximum(99999);
        min->setValue(0);

        gridLayout_3->addWidget(min, 10, 4, 1, 2);

        line_2 = new QFrame(tab_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout_3->addWidget(line_2, 12, 0, 1, 6);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_3->addWidget(label_17, 14, 0, 1, 2);

        days = new QSpinBox(tab_2);
        days->setObjectName(QString::fromUtf8("days"));
        days->setValue(1);

        gridLayout_3->addWidget(days, 14, 2, 1, 1);

        months = new QComboBox(tab_2);
        months->setObjectName(QString::fromUtf8("months"));

        gridLayout_3->addWidget(months, 14, 3, 1, 1);

        years = new QSpinBox(tab_2);
        years->setObjectName(QString::fromUtf8("years"));
        years->setMinimum(1970);
        years->setMaximum(20000);
        years->setValue(1970);

        gridLayout_3->addWidget(years, 14, 4, 1, 1);

        alway = new QCheckBox(tab_2);
        alway->setObjectName(QString::fromUtf8("alway"));

        gridLayout_3->addWidget(alway, 14, 5, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_8, 5, 1, 1, 1);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 3, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_9, 7, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_10, 9, 1, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_11, 11, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_12, 13, 0, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_13, 15, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        userGroups = new QTreeView(tab_3);
        userGroups->setObjectName(QString::fromUtf8("userGroups"));
        userGroups->setGeometry(QRect(0, 0, 751, 311));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(userGroups->sizePolicy().hasHeightForWidth());
        userGroups->setSizePolicy(sizePolicy3);
        userGroups->setAutoFillBackground(false);
        userGroups->setFrameShape(QFrame::StyledPanel);
        userGroups->setFrameShadow(QFrame::Sunken);
        userGroups->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        userGroups->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userGroups->setAlternatingRowColors(true);
        userGroups->setSelectionBehavior(QAbstractItemView::SelectRows);
        userGroups->setRootIsDecorated(false);
        userGroups->setUniformRowHeights(true);
        userGroups->setSortingEnabled(true);
        userGroups->setAnimated(true);
        userGroups->setAllColumnsShowFocus(true);
        userGroups->setWordWrap(true);
        easyList = new QListWidget(tab_3);
        easyList->setObjectName(QString::fromUtf8("easyList"));
        easyList->setGeometry(QRect(4, 0, 311, 311));
        sizePolicy3.setHeightForWidth(easyList->sizePolicy().hasHeightForWidth());
        easyList->setSizePolicy(sizePolicy3);
        easyList->setAutoFillBackground(false);
        easyList->setProperty("isWrapping", QVariant(false));
        easyList->setViewMode(QListView::ListMode);
        easyList->setWordWrap(true);
        easyCheckbox = new QCheckBox(tab_3);
        easyCheckbox->setObjectName(QString::fromUtf8("easyCheckbox"));
        easyCheckbox->setGeometry(QRect(4, 320, 185, 28));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(easyCheckbox->sizePolicy().hasHeightForWidth());
        easyCheckbox->setSizePolicy(sizePolicy4);
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 320, 131, 28));
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setMaximumSize(QSize(16777215, 16777209));
        label->setScaledContents(false);
        label->setWordWrap(true);
        makePrimBtn = new QPushButton(tab_3);
        makePrimBtn->setObjectName(QString::fromUtf8("makePrimBtn"));
        makePrimBtn->setGeometry(QRect(560, 320, 184, 28));
        primGroupLabel = new QLabel(tab_3);
        primGroupLabel->setObjectName(QString::fromUtf8("primGroupLabel"));
        primGroupLabel->setGeometry(QRect(440, 320, 121, 28));
        primGroupLabel->setStyleSheet(QString::fromUtf8("selection-color: red"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 4);

        cancelBtn->raise();
        edit->raise();
        tabWidget->raise();

        retranslateUi(EditProperties);
        QObject::connect(cancelBtn, SIGNAL(clicked()), EditProperties, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EditProperties);
    } // setupUi

    void retranslateUi(QDialog *EditProperties)
    {
        EditProperties->setWindowTitle(QApplication::translate("EditProperties", "User Properties", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("EditProperties", "&Close", 0, QApplication::UnicodeUTF8));
        edit->setText(QApplication::translate("EditProperties", "&Ok", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EditProperties", "User Login :", 0, QApplication::UnicodeUTF8));
        LoginName->setText(QString());
        pass->setText(QApplication::translate("EditProperties", "&Set Password ....", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EditProperties", "User ID :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EditProperties", "Full Name :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("EditProperties", "Shell Connection :", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("EditProperties", "Home Directory :", 0, QApplication::UnicodeUTF8));
        browseBtn->setText(QApplication::translate("EditProperties", "Browse...", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("EditProperties", "Office  1# :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("EditProperties", "Office  2# :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("EditProperties", "Address :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("EditProperties", "Account Disabled  :", 0, QApplication::UnicodeUTF8));
        checkBoxEdit->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EditProperties", "User &Info", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EditProperties", "Last Password Change :", 0, QApplication::UnicodeUTF8));
        datetime->setText(QString());
        label_9->setText(QApplication::translate("EditProperties", "Password Aging :", 0, QApplication::UnicodeUTF8));
        requires_Pass->setText(QString());
        max->setSuffix(QApplication::translate("EditProperties", "  days", 0, QApplication::UnicodeUTF8));
        max->setPrefix(QString());
        label_14->setText(QApplication::translate("EditProperties", "Warn before password expires :", 0, QApplication::UnicodeUTF8));
        warn->setSpecialValueText(QString());
        warn->setSuffix(QApplication::translate("EditProperties", "  days", 0, QApplication::UnicodeUTF8));
        warn->setPrefix(QApplication::translate("EditProperties", "After ", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("EditProperties", "Disable account after password expires :", 0, QApplication::UnicodeUTF8));
        expire->setSpecialValueText(QString());
        expire->setSuffix(QApplication::translate("EditProperties", "  days", 0, QApplication::UnicodeUTF8));
        enforce_Pass->setText(QString());
        label_16->setText(QApplication::translate("EditProperties", "Enforce minimum password age:", 0, QApplication::UnicodeUTF8));
        min->setSpecialValueText(QString());
        min->setSuffix(QApplication::translate("EditProperties", "  days", 0, QApplication::UnicodeUTF8));
        min->setPrefix(QString());
        label_17->setText(QApplication::translate("EditProperties", "Account will expire  on:", 0, QApplication::UnicodeUTF8));
        months->clear();
        months->insertItems(0, QStringList()
         << QApplication::translate("EditProperties", "January ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "February", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "March", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "April", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "May", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "June ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "July", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "August", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "September", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "October", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "November", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditProperties", "December", 0, QApplication::UnicodeUTF8)
        );
        alway->setText(QApplication::translate("EditProperties", "Never", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("EditProperties", "Require new password after:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("EditProperties", "Password &Manager", 0, QApplication::UnicodeUTF8));
        easyCheckbox->setText(QApplication::translate("EditProperties", "Privileges and groups", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EditProperties", "Primary Group:", 0, QApplication::UnicodeUTF8));
        makePrimBtn->setText(QApplication::translate("EditProperties", "Set as Primary", 0, QApplication::UnicodeUTF8));
        primGroupLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("EditProperties", "&Groups", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditProperties: public Ui_EditProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPROPERTIES_H
