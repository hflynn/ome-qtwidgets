/*
 * #%L
 * OME-QTWIDGETS C++ library for display of OME-Files pixel data and metadata.
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

#include <ome/qtwidgets/TexelProperties.h>

#include <stdexcept>

namespace ome
{
  namespace qtwidgets
  {

    // No switch default to avoid -Wunreachable-code errors.
    // However, this then makes -Wswitch-default complain.  Disable
    // temporarily.
#ifdef __GNUC__
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wswitch-default"
#endif

#define INTERNALFORMAT_CASE(maR, maProperty, maType)                    \
        case ::ome::xml::model::enums::PixelType::maType:               \
          internal_format = TexelProperties<::ome::xml::model::enums::PixelType::maType>::internal_format; \
          break;

    GLenum
    textureInternalFormat(::ome::xml::model::enums::PixelType pixeltype)
    {
      GLenum internal_format = 0;

      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(INTERNALFORMAT_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return internal_format;
    }

#undef INTERNALFORMAT_CASE

#define EXTERNALFORMAT_CASE(maR, maProperty, maType)                    \
        case ::ome::xml::model::enums::PixelType::maType:               \
          external_format = TexelProperties<::ome::xml::model::enums::PixelType::maType>::external_format; \
          break;

    GLenum
    textureExternalFormat(::ome::xml::model::enums::PixelType pixeltype)
    {
      GLenum external_format = 0;

      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(EXTERNALFORMAT_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return external_format;
    }

#undef EXTERNALFORMAT_CASE

#define EXTERNALTYPE_CASE(maR, maProperty, maType)                      \
        case ::ome::xml::model::enums::PixelType::maType:               \
          external_type = TexelProperties<::ome::xml::model::enums::PixelType::maType>::external_type; \
          break;

    GLint
    textureExternalType(::ome::xml::model::enums::PixelType pixeltype)
    {
      GLint external_type = 0;

      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(EXTERNALTYPE_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return external_type;
    }

#undef EXTERNALTYPE_CASE

#define FALLBACKTYPE_CASE(maR, maProperty, maType)                      \
        case ::ome::xml::model::enums::PixelType::maType:               \
          fallback_pixeltype = TexelProperties<::ome::xml::model::enums::PixelType::maType>::fallback_pixeltype; \
          break;

    ::ome::xml::model::enums::PixelType
    texturePixelTypeFallback(::ome::xml::model::enums::PixelType pixeltype)
    {
      ome::xml::model::enums::PixelType fallback_pixeltype = ome::xml::model::enums::PixelType::UINT8;

      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(FALLBACKTYPE_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return fallback_pixeltype;
    }

#undef FALLBACKTYPE_CASE

#define CONVERSION_CASE(maR, maProperty, maType)                        \
        case ::ome::xml::model::enums::PixelType::maType:               \
          conversion_required = TexelProperties<::ome::xml::model::enums::PixelType::maType>::conversion_required; \
          break;

    bool
    textureConversionRequired(::ome::xml::model::enums::PixelType pixeltype)
    {
      bool conversion_required = false;

      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(CONVERSION_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return conversion_required;
    }

#undef CONVERSION_CASE

#define NORMALIZATION_CASE(maR, maProperty, maType)                     \
        case ::ome::xml::model::enums::PixelType::maType:               \
          normalization_required = TexelProperties<::ome::xml::model::enums::PixelType::maType>::normalization_required; \
          break;

    bool
    textureNormalizationRequired(::ome::xml::model::enums::PixelType pixeltype)
    {
      bool normalization_required = false;

      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(NORMALIZATION_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return normalization_required;
    }

#undef NORMALIZATION_CASE

#define MINIFICATION_CASE(maR, maProperty, maType)                      \
        case ::ome::xml::model::enums::PixelType::maType:               \
          minification_filter = TexelProperties<::ome::xml::model::enums::PixelType::maType>::minification_filter; \
          break;

    GLint
    textureMinificationFilter(::ome::xml::model::enums::PixelType pixeltype)
    {
      GLint minification_filter = false; 
      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(MINIFICATION_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return minification_filter;
    }

#undef MINIFICATION_CASE

#define MAGNIFICATION_CASE(maR, maProperty, maType)                     \
        case ::ome::xml::model::enums::PixelType::maType:               \
          magnification_filter = TexelProperties<::ome::xml::model::enums::PixelType::maType>::magnification_filter; \
          break;

    GLint
    textureMagnificationFilter(::ome::xml::model::enums::PixelType pixeltype)
    {
      GLint magnification_filter = false; 
      switch(pixeltype)
        {
          BOOST_PP_SEQ_FOR_EACH(MAGNIFICATION_CASE, size, OME_XML_MODEL_ENUMS_PIXELTYPE_VALUES);
        }

      return magnification_filter;
    }

#undef MAGNIFICATION_CASE

#ifdef __GNUC__
#  pragma GCC diagnostic pop
#endif

    GLenum
    textureInternalFormatFallback(GLenum format)
    {
      GLenum ret = GL_R8;

      switch(format)
        {
          // R
        case GL_R32F:
          ret = GL_R16F;
          break;
        case GL_R16F:
          ret = GL_R16;
          break;
        case GL_R16:
          ret = GL_R8;
          break;

          // RG
        case GL_RG32F:
          ret = GL_R16F;
          break;
        case GL_RG16F:
          ret = GL_RG16;
          break;
        case GL_RG16:
          ret = GL_RG8;
          break;

          // RGB
        case GL_RGB32F:
          ret = GL_RGB16F;
          break;
        case GL_RGB16F:
          ret = GL_RGB16;
          break;
        case GL_RGB16:
          ret = GL_RGB8;
          break;

          // RGBA
        case GL_RGBA32F:
          ret = GL_RGBA16F;
          break;
        case GL_RGBA16F:
          ret = GL_RGBA16;
          break;
        case GL_RGBA16:
          ret = GL_RGBA8;
          break;

        default:
          ret = GL_R8;
          break;
        }

      return ret;
    }

  }
}
