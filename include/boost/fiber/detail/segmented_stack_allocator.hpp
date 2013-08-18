
//          Copyright Oliver Kowalke 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FIBERS_DETAIL_SEGMENTED_STACK_ALLOCATOR_H
#define BOOST_FIBERS_DETAIL_SEGMENTED_STACK_ALLOCATOR_H

#include <cstddef>

#include <boost/config.hpp>

#include <boost/fiber/detail/config.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_PREFIX
#endif

namespace boost {
namespace fibers {

struct stack_context;

namespace detail {

#if defined(BOOST_USE_SEGMENTED_STACKS)
class segmented_stack_allocator
{
public:
    static bool is_stack_unbound();

    static std::size_t default_stacksize();

    static std::size_t minimum_stacksize();

    static std::size_t maximum_stacksize();

    void allocate( stack_context &, std::size_t = minimum_stacksize() );

    void deallocate( stack_context &);
};
#endif

}}}

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
#endif

#endif // BOOST_FIBERS_DETAIL_SEGMENTED_STACK_ALLOCATOR_H