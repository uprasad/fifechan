/***************************************************************************
 *   Copyright (C) 2012 by the fifechan team                               *
 *   http://fifechan.github.com/fifechan                                   *
 *   This file is part of fifechan.                                        *
 *                                                                         *
 *   fifechan is free software; you can redistribute it and/or             *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/

/*      _______   __   __   __   ______   __   __   _______   __   __
 *     / _____/\ / /\ / /\ / /\ / ____/\ / /\ / /\ / ___  /\ /  |\/ /\
 *    / /\____\// / // / // / // /\___\// /_// / // /\_/ / // , |/ / /
 *   / / /__   / / // / // / // / /    / ___  / // ___  / // /| ' / /
 *  / /_// /\ / /_// / // / // /_/_   / / // / // /\_/ / // / |  / /
 * /______/ //______/ //_/ //_____/\ /_/ //_/ //_/ //_/ //_/ /|_/ /
 * \______\/ \______\/ \_\/ \_____\/ \_\/ \_\/ \_\/ \_\/ \_\/ \_\/
 *
 * Copyright (c) 2004 - 2008 Olof Naess�n and Per Larsson
 *
 *
 * Per Larsson a.k.a finalman
 * Olof Naess�n a.k.a jansem/yakslem
 *
 * Visit: http://guichan.sourceforge.net
 *
 * License: (BSD)
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Guichan nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * For comments regarding functions please see the header file.
 */

#include "fifechan/widgets/container.hpp"

#include "fifechan/exception.hpp"
#include "fifechan/graphics.hpp"

namespace fcn
{
    Container::Container()
    {
        mOpaque = true;
    }

    Container::~Container()
    {
    }

    void Container::draw(Graphics* graphics)
    {
        if (isOpaque())
        {
            graphics->setColor(getBaseColor());
            graphics->fillRectangle(0, 0, getWidth(), getHeight());
        }
    }

    void Container::setOpaque(bool opaque)
    {
        mOpaque = opaque;
    }

    bool Container::isOpaque() const
    {
        return mOpaque;
    }

    void Container::add(Widget* widget)
    {
        Widget::add(widget);
        distributeWidgetAddedEvent(widget);
    }

    void Container::add(Widget* widget, int x, int y)
    {
        widget->setPosition(x, y);
        Widget::add(widget);
        distributeWidgetAddedEvent(widget);
    }

    void Container::remove(Widget* widget)
    {
        Widget::remove(widget);
        distributeWidgetRemovedEvent(widget);
    }

    void Container::clear()
    {
        Widget::clear();
    }

    Widget* Container::findWidgetById(const std::string &id)
    {
        return Widget::findWidgetById(id);
    }

    void Container::addContainerListener(ContainerListener* containerListener)
    {
        mContainerListeners.push_back(containerListener);
    }
   
    void Container::removeContainerListener(ContainerListener* containerListener)
    {
        mContainerListeners.remove(containerListener);
    }

    void Container::distributeWidgetAddedEvent(Widget* source)
    {
        ContainerListenerIterator iter;

        for (iter = mContainerListeners.begin(); iter != mContainerListeners.end(); ++iter)
        {
            ContainerEvent event(source, this);
            (*iter)->widgetAdded(event);
        }
    }
    
    void Container::distributeWidgetRemovedEvent(Widget* source)
    {
        ContainerListenerIterator iter;

        for (iter = mContainerListeners.begin(); iter != mContainerListeners.end(); ++iter)
        {
            ContainerEvent event(source, this);
            (*iter)->widgetRemoved(event);
        }
    }

    const std::list<Widget*>& Container::getChildren() const
    {
        return Widget::getChildren();
    }

    void Container::resizeToContent()
    {
        Widget::resizeToChildren();
    }

    Rectangle Container::getChildrenArea()
    {
        return Rectangle(0, 0, getWidth(), getHeight());
    }
}
