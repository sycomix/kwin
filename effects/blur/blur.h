/*
 *   Copyright © 2010 Fredrik Höglund <fredrik@kde.org>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; see the file COPYING.  if not, write to
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *   Boston, MA 02110-1301, USA.
 */

#ifndef BLUR_H
#define BLUR_H 

#include <kwineffects.h>
#include <kwinglutils.h>

#include <QVector>
#include <QVector2D>

namespace KWin
{

class BlurShader;

class BlurEffect : public KWin::Effect
{
public:
    BlurEffect();
    ~BlurEffect();

    static bool supported();

    void windowAdded(EffectWindow *w);
    void propertyNotify(EffectWindow *w, long atom);
    void paintScreen(int mask, QRegion region, ScreenPaintData &data);
    void drawWindow(EffectWindow *w, int mask, QRegion region, WindowPaintData &data);

private:
    QRect expand(const QRect &rect) const;
    QRegion expand(const QRegion &region) const;
    QRegion blurRegion(const EffectWindow *w) const;
    void updateBlurRegion(EffectWindow *w) const;

private:
    BlurShader *shader;
    QVector<QVector2D> vertices;
    QVector<QVector2D> texCoords;
    GLRenderTarget *target;
    GLTexture *tex;
    long net_wm_blur_region;
    int radius;
};

} // namespace KWin

#endif

