/*
 *    _aaaa,  _aa.  sa,  aaa              _aaaa,_  ac  .aa.   .aa.  .aa,  _a, sa
 *  .wWV!!!T  |Wm;  dQ[  $WF            _mWT!"?Y  ]QE  :Q#:   ]QW[  :WWk. ]Q[ dW
 * .jWf       :WW: .dQ[  dQ[           .mW(       )WE  :Q#:  .mSQh. :mWQa.]W[ dQ
 * |QW:       :Wm;  mQ[  dQ[           ]Qk        )Qmi_aQW:  <B:$Qc :WBWQ()W[ dQ
 * |W#:  .ww  ;WW;  dQ[  dQ[  .......  ]Qk        )QB?YYW#:  jf ]Qp.:mE)Qm]Q[ )W
 * +WQ;  :Wm  |Wm; .mQ[  dQ[ :qgggggga ]Qm.       ]WE  :Q# :=QasuQm;:Wk 3QQW[ )Y
 *  ]Wmi.:Wm  +$Q; .mW(  dQ[  !"!!"!!^ dQk,  ._   ]WE  :Q# :3D"!!$Qc.Wk -$WQ[   
 *   "?????? ` "?!=m?!   ??'            -??????!  -?!  -?? -?'   "?"-?"  "??' "?
 *
 * Copyright (c) 2004 darkbits                              Js_./
 * Per Larsson a.k.a finalman                          _RqZ{a<^_aa
 * Olof Naess�n a.k.a jansem/yakslem                _asww7!uY`>  )\a//
 *                                                 _Qhm`] _f "'c  1!5m
 * Visit: http://guichan.darkbits.org             )Qk<P ` _: :+' .'  "{[
 *                                               .)j(] .d_/ '-(  P .   S
 * License: (BSD)                                <Td/Z <fP"5(\"??"\a.  .L
 * Redistribution and use in source and          _dV>ws?a-?'      ._/L  #'
 * binary forms, with or without                 )4d[#7r, .   '     )d`)[
 * modification, are permitted provided         _Q-5'5W..j/?'   -?!\)cam'
 * that the following conditions are met:       j<<WP+k/);.        _W=j f
 * 1. Redistributions of source code must       .$%w\/]Q  . ."'  .  mj$
 *    retain the above copyright notice,        ]E.pYY(Q]>.   a     J@\
 *    this list of conditions and the           j(]1u<sE"L,. .   ./^ ]{a
 *    following disclaimer.                     4'_uomm\.  )L);-4     (3=
 * 2. Redistributions in binary form must        )_]X{Z('a_"a7'<a"a,  ]"[
 *    reproduce the above copyright notice,       #}<]m7`Za??4,P-"'7. ).m
 *    this list of conditions and the            ]d2e)Q(<Q(  ?94   b-  LQ/
 *    following disclaimer in the                <B!</]C)d_, '(<' .f. =C+m
 *    documentation and/or other materials      .Z!=J ]e []('-4f _ ) -.)m]'
 *    provided with the distribution.          .w[5]' _[ /.)_-"+?   _/ <W"
 * 3. Neither the name of darkbits nor the     :$we` _! + _/ .        j?
 *    names of its contributors may be used     =3)= _f  (_yQmWW$#(    "
 *    to endorse or promote products derived     -   W,  sQQQQmZQ#Wwa]..
 *    from this software without specific        (js, \[QQW$QWW#?!V"".
 *    prior written permission.                    ]y:.<\..          .
 *                                                 -]n w/ '         [.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT       )/ )/           !
 * HOLDERS AND CONTRIBUTORS "AS IS" AND ANY         <  (; sac    ,    '
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING,               ]^ .-  %
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF            c <   r
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR            aga<  <La
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE          5%  )P'-3L
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR        _bQf` y`..)a
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,          ,J?4P'.P"_(\?d'.,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES               _Pa,)!f/<[]/  ?"
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT      _2-..:. .r+_,.. .
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     ?a.<%"'  " -'.a_ _,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION)                     ^
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * For comments regarding functions please see the header file. 
 */

#include "guichan/key.hpp"

namespace gcn
{
  Key::Key()
  {
    mValue = 0;
    mShiftPressed = false;
    mControlPressed = false;
    mAltPressed = false;  
    mMetaPressed = false;
    mNumericPad = false;
    
  } // end Key
  
  Key::Key(int value)
  {
    mValue = value;
    mShiftPressed = false;
    mControlPressed = false;
    mAltPressed = false;
    mMetaPressed = false;
    mNumericPad = false;
    
  } // end Key

  bool Key::isCharacter() const
  {
    return (mValue >= 32 && mValue <= 126)
      || (mValue >= 162)
      || (mValue == 9);

  } // end isCharacter

  bool Key::isNumber() const
  {
    return mValue >= 48 && mValue <= 57;

  } // end isNumber
  
  bool Key::isLetter() const
  {
    return ((mValue >= 65 && mValue <= 90)
            || (mValue >= 97 && mValue <= 122)
            || (mValue >= 192)
            && (mValue != 215) && (mValue != 247));

  } // end isLetter

  bool Key::isShiftPressed() const
  {
    return mShiftPressed;

  } // end isShiftPressed
  
  void Key::setShiftPressed(bool pressed)
  {
    mShiftPressed = pressed;

  } // end setShiftPressed

  bool Key::isControlPressed() const
  {
    return mControlPressed;

  } // end isControlPressed
  
  void Key::setControlPressed(bool pressed)
  {
    mControlPressed = pressed;

  } // end setControlPressed

  bool Key::isAltPressed() const
  {
    return mAltPressed;

  } // end isAltPressed
  
  void Key::setAltPressed(bool pressed)
  {
    mAltPressed = pressed;

  } // end setAltPressed

  bool Key::isMetaPressed() const
  {
    return mMetaPressed;

  } // end isMetaPressed
  
  void Key::setMetaPressed(bool pressed)
  {
    mMetaPressed = pressed;

  } // end setMetaPressed

  bool Key::isNumericPad() const
  {
    return mNumericPad;

  } // end isNumericPad
  
  void Key::setNumericPad(bool numpad)
  {
    mNumericPad = numpad;

  } // end setNumericPad

  void Key::setValue(int value)
  {
    mValue = value;
    
  } // end setValue

  int Key::getValue() const
  {
    return mValue;
    
  } // end getValue

} // end gcn
