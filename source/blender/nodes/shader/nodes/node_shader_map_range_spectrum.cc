/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2005 Blender Foundation.
 * All rights reserved.
 */

/** \file
 * \ingroup shdnodes
 */

#include "node_shader_util.h"

/* **************** Map Range ******************** */
static bNodeSocketTemplate sh_node_map_range_spectrum_in[] = {
    {SOCK_RGBA, N_("Value"), 0.8f, 0.8f, 0.8f, 1.0f, 0.0f, 1.0f, PROP_NONE},
    {SOCK_RGBA, N_("From Min"), 0.0f, 0.0f, 0.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_RGBA, N_("From Max"), 1.0f, 1.0f, 1.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_RGBA, N_("To Min"), 0.0f, 0.0f, 0.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {SOCK_RGBA, N_("To Max"), 1.0f, 1.0f, 1.0f, 1.0f, -10000.0f, 10000.0f, PROP_NONE},
    {-1, ""},
};
static bNodeSocketTemplate sh_node_map_range_spectrum_out[] = {
    {SOCK_RGBA, N_("Result")},
    {-1, ""},
};
static void node_shader_init_map_range(bNodeTree *UNUSED(ntree), bNode *node)
{
  node->custom1 = true; /* use_clamp */
}

void register_node_type_sh_map_range_spectrum(void)
{
  static bNodeType ntype;

  sh_fn_node_type_base(
      &ntype, SH_NODE_MAP_RANGE_SPECTRUM, "Map Range Spectrum", NODE_CLASS_CONVERTOR, 0);
  node_type_socket_templates(
      &ntype, sh_node_map_range_spectrum_in, sh_node_map_range_spectrum_out);
  node_type_init(&ntype, node_shader_init_map_range);

  nodeRegisterType(&ntype);
}
