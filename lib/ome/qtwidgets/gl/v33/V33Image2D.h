/*
 * #%L
 * OME-QTWIDGETS C++ library for display of OME-Files pixel data and metadata.
 * %%
 * Copyright © 2014 - 2015 Open Microscopy Environment:
 *   - Massachusetts Institute of Technology
 *   - National Institutes of Health
 *   - University of Dundee
 *   - Board of Regents of the University of Wisconsin-Madison
 *   - Glencoe Software, Inc.
 * %%
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of any organization.
 * #L%
 */

#ifndef OME_QTWIDGETS_GL_V33_V33IMAGE2D_H
#define OME_QTWIDGETS_GL_V33_V33IMAGE2D_H

#include <QtCore/QObject>
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLShader>

#include <ome/files/Types.h>
#include <ome/files/FormatReader.h>

#include <ome/qtwidgets/gl/Image2D.h>
#include <ome/qtwidgets/glsl/v330/V330GLImageShader2D.h>

namespace ome
{
  namespace qtwidgets
  {
    /// OpenGL rendering.
    namespace gl
    {
      /// OpenGL v3.3 (core profile).
      namespace v33
      {

        /**
         * 2D (xy) image renderer.
         *
         * Draws the specified image, using a user-selectable plane.
         *
         * The render is greyscale with a per-channel min/max for linear
         * contrast.
         */
        class Image2D : public gl::Image2D
        {
          Q_OBJECT

        public:
          /**
           * Create a 2D image.
           *
           * The size and position will be taken from the specified image.
           *
           * @param reader the image reader.
           * @param series the image series.
           * @param parent the parent of this object.
           */
          explicit Image2D(std::shared_ptr<ome::files::FormatReader>  reader,
                           ome::files::dimension_size_type                    series,
                           QObject                                           *parent = 0);

          /// Destructor.
          virtual ~Image2D();

          void
          render(const glm::mat4& mvp);

        private:
          /// The shader program for image rendering.
          glsl::v330::GLImageShader2D *image_shader;
        };

      }
    }
  }
}

#endif // OME_QTWIDGETS_GL_V33_V33IMAGE2D_H

/*
 * Local Variables:
 * mode:C++
 * End:
 */
