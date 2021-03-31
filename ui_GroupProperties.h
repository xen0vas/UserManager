/********************************************************************************
** Form generated from reading UI file 'GroupProperties.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPPROPERTIES_H
#define UI_GROUPPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_GroupProperties
{
public:
    QLabel *GIDLabel;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLineEdit *GIDEdit;
    QToolButton *newGroupBtn;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *groupNameEdit;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *existsLabel;
    QFrame *line;
    QGridLayout *gridLayout;
    QTreeView *membersList;
    QSpacerItem *verticalSpacer;
    QTreeView *notMembersList;
    QGridLayout *gridLayout1;
    QPushButton *addBtn;
    QPushButton *removeBtn;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *closeBtn;
    QFrame *line_2;

    void setupUi(QDialog *GroupProperties)
    {
        if (GroupProperties->objectName().isEmpty())
            GroupProperties->setObjectName(QStringLiteral("GroupProperties"));
        GroupProperties->resize(450, 448);
        GroupProperties->setMouseTracking(false);
        GroupProperties->setFocusPolicy(Qt::StrongFocus);
        GroupProperties->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/images/editGroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        GroupProperties->setWindowIcon(icon);
        GroupProperties->setSizeGripEnabled(false);
        GIDLabel = new QLabel(GroupProperties);
        GIDLabel->setObjectName(QStringLiteral("GIDLabel"));
        GIDLabel->setGeometry(QRect(110, 16, 63, 17));
        gridLayout_3 = new QGridLayout(GroupProperties);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(GroupProperties);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        GIDEdit = new QLineEdit(GroupProperties);
        GIDEdit->setObjectName(QStringLiteral("GIDEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GIDEdit->sizePolicy().hasHeightForWidth());
        GIDEdit->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(GIDEdit, 0, 1, 1, 1);

        newGroupBtn = new QToolButton(GroupProperties);
        newGroupBtn->setObjectName(QStringLiteral("newGroupBtn"));
        newGroupBtn->setCursor(QCursor(Qt::OpenHandCursor));
        newGroupBtn->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/images/addgr.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        newGroupBtn->setIcon(icon1);
        newGroupBtn->setIconSize(QSize(50, 40));

        gridLayout_3->addWidget(newGroupBtn, 0, 2, 3, 1);

        horizontalSpacer_2 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 3, 2, 2);

        groupNameEdit = new QLineEdit(GroupProperties);
        groupNameEdit->setObjectName(QStringLiteral("groupNameEdit"));
        groupNameEdit->setFocusPolicy(Qt::ClickFocus);
        groupNameEdit->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(groupNameEdit, 1, 1, 2, 1);

        label_2 = new QLabel(GroupProperties);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        existsLabel = new QLabel(GroupProperties);
        existsLabel->setObjectName(QStringLiteral("existsLabel"));
        sizePolicy.setHeightForWidth(existsLabel->sizePolicy().hasHeightForWidth());
        existsLabel->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(existsLabel, 3, 1, 1, 1);

        line = new QFrame(GroupProperties);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 4, 0, 1, 5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        membersList = new QTreeView(GroupProperties);
        membersList->setObjectName(QStringLiteral("membersList"));
        membersList->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(membersList->sizePolicy().hasHeightForWidth());
        membersList->setSizePolicy(sizePolicy1);
        membersList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        membersList->setAcceptDrops(true);
        membersList->setAutoFillBackground(true);
        membersList->setStyleSheet(QStringLiteral("selection-background-color: red"));
        membersList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        membersList->setProperty("showDropIndicator", QVariant(false));
        membersList->setAlternatingRowColors(true);
        membersList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        membersList->setRootIsDecorated(false);
        membersList->setSortingEnabled(true);
        membersList->setAnimated(true);
        membersList->setAllColumnsShowFocus(true);
        membersList->setWordWrap(true);

        gridLayout->addWidget(membersList, 0, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        notMembersList = new QTreeView(GroupProperties);
        notMembersList->setObjectName(QStringLiteral("notMembersList"));
        sizePolicy1.setHeightForWidth(notMembersList->sizePolicy().hasHeightForWidth());
        notMembersList->setSizePolicy(sizePolicy1);
        notMembersList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        notMembersList->setAcceptDrops(true);
        notMembersList->setAutoFillBackground(true);
        notMembersList->setStyleSheet(QStringLiteral("selection-background-color: red"));
        notMembersList->setFrameShape(QFrame::StyledPanel);
        notMembersList->setFrameShadow(QFrame::Sunken);
        notMembersList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        notMembersList->setAlternatingRowColors(true);
        notMembersList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        notMembersList->setRootIsDecorated(false);
        notMembersList->setSortingEnabled(true);
        notMembersList->setAnimated(true);
        notMembersList->setAllColumnsShowFocus(true);
        notMembersList->setWordWrap(true);

        gridLayout->addWidget(notMembersList, 0, 2, 3, 1);

        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        addBtn = new QPushButton(GroupProperties);
        addBtn->setObjectName(QStringLiteral("addBtn"));

        gridLayout1->addWidget(addBtn, 0, 0, 1, 1);

        removeBtn = new QPushButton(GroupProperties);
        removeBtn->setObjectName(QStringLiteral("removeBtn"));

        gridLayout1->addWidget(removeBtn, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout1, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 5, 0, 1, 5);

        horizontalSpacer = new QSpacerItem(270, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 6, 0, 1, 2);

        okBtn = new QPushButton(GroupProperties);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/images/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        okBtn->setIcon(icon2);

        gridLayout_3->addWidget(okBtn, 6, 2, 1, 2);

        closeBtn = new QPushButton(GroupProperties);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/images/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon3);

        gridLayout_3->addWidget(closeBtn, 6, 4, 1, 1);

        line_2 = new QFrame(GroupProperties);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 7, 0, 1, 5);


        retranslateUi(GroupProperties);
        QObject::connect(closeBtn, SIGNAL(clicked()), GroupProperties, SLOT(close()));

        QMetaObject::connectSlotsByName(GroupProperties);
    } // setupUi

    void retranslateUi(QDialog *GroupProperties)
    {
        GroupProperties->setWindowTitle(QApplication::translate("GroupProperties", "Group Properties", Q_NULLPTR));
        GIDLabel->setText(QString());
        label->setText(QApplication::translate("GroupProperties", "Group ID:", Q_NULLPTR));
        newGroupBtn->setText(QApplication::translate("GroupProperties", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("GroupProperties", "Group Name:", Q_NULLPTR));
        existsLabel->setText(QString());
        addBtn->setText(QApplication::translate("GroupProperties", "<- Add", Q_NULLPTR));
        removeBtn->setText(QApplication::translate("GroupProperties", "Remove->", Q_NULLPTR));
        okBtn->setText(QApplication::translate("GroupProperties", "&OK", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("GroupProperties", "&Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GroupProperties: public Ui_GroupProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPPROPERTIES_H
