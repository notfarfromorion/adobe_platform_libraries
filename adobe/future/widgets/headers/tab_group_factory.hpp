/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/****************************************************************************************************/

#ifndef ADOBE_TAB_GROUP_FACTORY_HPP
#define ADOBE_TAB_GROUP_FACTORY_HPP

/****************************************************************************************************/

#include <adobe/dictionary.hpp>
#include <adobe/eve.hpp>

/****************************************************************************************************/

namespace adobe {

/****************************************************************************************************/

struct widget_node_t;
struct factory_token_t;
class widget_factory_t;

/****************************************************************************************************/

widget_node_t make_tab_group(const dictionary_t&     parameters,
                             const widget_node_t&    parent,
                             const factory_token_t&  token,
                             const widget_factory_t& factory);

/****************************************************************************************************/

inline const layout_attributes_t& tab_group_layout_attributes()
{
    static layout_attributes_t result;
    static bool                       inited(false);

    if (!inited)
    {
        inited = true;

        result.placement_m = eve_t::place_overlay;
        result.vertical().suppress_m = false; // Allow baselines to propagate
        set_margin(result, 10); /* REVISIT FIXED VALUE dialog_margin */
    }

    return result;
}

/****************************************************************************************************/

} // namespace adobe

/****************************************************************************************************/

#endif

/****************************************************************************************************/
