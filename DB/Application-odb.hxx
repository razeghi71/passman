// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef APPLICATION_ODB_HXX
#define APPLICATION_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "Application.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // Application
  //
  template <>
  struct class_traits< ::Application >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::Application >
  {
    public:
    typedef ::Application object_type;
    typedef ::Application* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef int id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // Application
  //
  template <typename A>
  struct query_columns< ::Application, id_mysql, A >
  {
    // app_id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        int,
        mysql::id_long >::query_type,
      mysql::id_long >
    app_id_type_;

    static const app_id_type_ app_id;

    // executable_path
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    executable_path_type_;

    static const executable_path_type_ executable_path;

    // executable_hash
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    executable_hash_type_;

    static const executable_hash_type_ executable_hash;
  };

  template <typename A>
  const typename query_columns< ::Application, id_mysql, A >::app_id_type_
  query_columns< ::Application, id_mysql, A >::
  app_id (A::table_name, "`app_id`", 0);

  template <typename A>
  const typename query_columns< ::Application, id_mysql, A >::executable_path_type_
  query_columns< ::Application, id_mysql, A >::
  executable_path (A::table_name, "`executable_path`", 0);

  template <typename A>
  const typename query_columns< ::Application, id_mysql, A >::executable_hash_type_
  query_columns< ::Application, id_mysql, A >::
  executable_hash (A::table_name, "`executable_hash`", 0);

  template <typename A>
  struct pointer_query_columns< ::Application, id_mysql, A >:
    query_columns< ::Application, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::Application, id_mysql >:
    public access::object_traits< ::Application >
  {
    public:
    struct id_image_type
    {
      int id_value;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // app_id
      //
      int app_id_value;
      my_bool app_id_null;

      // executable_path
      //
      details::buffer executable_path_value;
      unsigned long executable_path_size;
      my_bool executable_path_null;

      // executable_hash
      //
      details::buffer executable_hash_value;
      unsigned long executable_hash_size;
      my_bool executable_hash_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::Application, id_common >:
    public access::object_traits_impl< ::Application, id_mysql >
  {
  };

  // Application
  //
}

#include "Application-odb.ixx"

#include <odb/post.hxx>

#endif // APPLICATION_ODB_HXX