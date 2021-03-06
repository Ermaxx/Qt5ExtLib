/****************************************************************************
** 
** Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
** 
** This file is part of a Qt Solutions component.
**
** Commercial Usage  
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Solutions Commercial License Agreement provided
** with the Software or, alternatively, in accordance with the terms
** contained in a written agreement between you and Nokia.
** 
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
** 
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.1, included in the file LGPL_EXCEPTION.txt in this
** package.
** 
** GNU General Public License Usage 
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
** 
** Please note Third Party Software included with Qt Solutions may impose
** additional restrictions and it is the user's responsibility to ensure
** that they have met the licensing requirements of the GPL, LGPL, or Qt
** Solutions Commercial license and the relevant license of the Third
** Party Software they are using.
** 
** If you are unsure which license is appropriate for your use, please
** contact Nokia at qt-info@nokia.com.
** 
****************************************************************************/

#include "qtpiemenu.h"
#include "qtpieaction.h"

/*! \internal

    Constructs a QtPieAction. The \a title argument is the human
    readable title of this action, such as "New", "Open" or "Select".

    The \a receiver is a QObject in which the signal or slot \a member
    will be called when this item is activated.
*/
QtPieAction::QtPieAction(const QString &text,
                         QObject *receiver, const char *member, QVariant data )
    : QtPieItem(text), mData( data )
{
    connect(this, SIGNAL(activated()), receiver, member);
}

/*! \internal

    Constructs a QtPieAction. The \a title argument is the human
    readable text label of this action, such as "New", "Open" or "Select".
    The QIcon \a icons will be displayed together with the text,
    or by itself if \a title is empty.

    The \a receiver is a QObject in which the signal or slot \a member
    will be called when this item is activated.
*/
QtPieAction::QtPieAction(const QIcon &icons, const QString &text,
                         QObject *receiver, const char *member, QVariant data )
    : QtPieItem(icons, text), mData( data )
{
    connect(this, SIGNAL(activated()), receiver, member);
}

/*! \internal

    Returns the type of QtPieItem, in this case always Action.
*/
int QtPieAction::type() const
{
    return QtPieMenu::Action;
}

/*! \internal

    This function is called by the QtPieMenu parent when the item that
    holds this QtPieAction is activated.
*/
void QtPieAction::activate()
{
    emit activated();
}


QVariant QtPieAction::data() const
{
    return mData;
}
