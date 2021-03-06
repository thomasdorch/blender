/*
 * Copyright 2011-2017 Blender Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __UTIL_TYPES_SPECTRAL_COLOR_H__
#define __UTIL_TYPES_SPECTRAL_COLOR_H__

#ifndef __UTIL_TYPES_H__
#  error "Do not include this file directly, include util_types.h instead."
#endif

CCL_NAMESPACE_BEGIN

#define SPECTRAL_COLOR_DATA_TYPE float8
#define SPECTRAL_CHANNELS_PER_RAY 8

#ifdef __WITH_SPECTRAL_RENDERING__
#  define SPECTRAL_COLOR_CURRENT_DATA_TYPE SPECTRAL_COLOR_DATA_TYPE
#  define CHANNELS_PER_RAY SPECTRAL_CHANNELS_PER_RAY
#else
#  define SPECTRAL_COLOR_CURRENT_DATA_TYPE float3
#  define CHANNELS_PER_RAY 3
#endif

typedef SPECTRAL_COLOR_CURRENT_DATA_TYPE SpectralColor;

#define make_spectral_color(f) CONCAT(make_, SPECTRAL_COLOR_CURRENT_DATA_TYPE(f))
#define load_spectral_color(f) CONCAT(load_, SPECTRAL_COLOR_CURRENT_DATA_TYPE(f))
#define store_spectral_color(s, f) CONCAT(store_, SPECTRAL_COLOR_CURRENT_DATA_TYPE((s), (f)))

#define zero_spectral_color CONCAT(zero_, SPECTRAL_COLOR_CURRENT_DATA_TYPE)
#define one_spectral_color CONCAT(one_, SPECTRAL_COLOR_CURRENT_DATA_TYPE)

#define spectral_color_to_float3(f) CONCAT(SPECTRAL_COLOR_CURRENT_DATA_TYPE, _to_float3(f))
#define float3_to_spectral_color(f) CONCAT(float3_to_, SPECTRAL_COLOR_CURRENT_DATA_TYPE(f))

#define FOR_EACH_CHANNEL(counter) for (int counter = 0; counter < CHANNELS_PER_RAY; counter++)

#define MIN_WAVELENGTH 380.0f
#define MAX_WAVELENGTH 730.0f

CCL_NAMESPACE_END

#endif /* __UTIL_TYPES_SPECTRAL_COLOR_H__ */
