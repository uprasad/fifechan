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

#ifndef FCN_HGEIMAGE_HPP
#define FCN_HGEIMAGE_HPP

#include <hge.h>
#include <hgesprite.h>
#include <string>

#include "fifechan/color.hpp"
#include "fifechan/platform.hpp"
#include "fifechan/image.hpp"

namespace fcn
{
    /**
     * HGE implementation of Image.
     *
     * @author Kevin Lynx
     * @since  0.6.1
     */
    class FCN_EXTENSION_DECLSPEC HGEImage : public Image
    {
    public:
        /**
         * Constructor. 
         * 
         * Creates an image from a HGE texture.
         *
         * NOTE : The functions getPixel and putPixel are only guaranteed to work
         * with a 32bits image.
         *
         * @param sprite A HGE texture to create the image from.
         * @param autoFree True it the image should be automatically deleted by 
         *                 the destructor, false otherwise. 
         */
        HGEImage(HTEXTURE texture, bool autoFree = false);

        /**
         * Destructor.
         *
         */
        ~HGEImage();

        /**
         * Gets the HGE sprite of the image.
         *
         * @return the HGE sprite of the image.
         */
        virtual hgeSprite *getSprite() const;

    
        // Inherited from Image

        virtual void free();
    
        virtual int getWidth() const;
    
        virtual int getHeight() const;

        virtual Color getPixel(int x, int y);
    
        virtual void putPixel(int x, int y, const Color &color);

        virtual void convertToDisplayFormat();

    protected:
        static HGE *mHGE;
        bool mAutoFree;
        hgeSprite *mHGESprite;
        HTEXTURE mTexture;
    };
}

#endif // end FCN_HGEIMAGE_HPP
