// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef APPLICATION_PASSWORD_ODB_HXX
#define APPLICATION_PASSWORD_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "ApplicationPassword.h"

#include "Application-odb.hxx"

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
  // ApplicationPassword
  //
  template <>
  struct class_traits< ::ApplicationPassword >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::ApplicationPassword >
  {
    public:
    typedef ::ApplicationPassword object_type;
    typedef ::ApplicationPassword* pointer_type;
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
  // ApplicationPassword
  //
  template <typename A>
  struct pointer_query_columns< ::ApplicationPassword, id_mysql, A >
  {
    // passwordID
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        int,
        mysql::id_long >::query_type,
      mysql::id_long >
    passwordID_type_;

    static const passwordID_type_ passwordID;

    // app
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        int,
        mysql::id_long >::query_type,
      mysql::id_long >
    app_type_;

    static const app_type_ app;

    // title
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    title_type_;

    static const title_type_ title;

    // url
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    url_type_;

    static const url_type_ url;

    // username
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    username_type_;

    static const username_type_ username;

    // password
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    password_type_;

    static const password_type_ password;
  };

  template <typename A>
  const typename pointer_query_columns< ::ApplicationPassword, id_mysql, A >::passwordID_type_
  pointer_query_columns< ::ApplicationPassword, id_mysql, A >::
  passwordID (A::table_name, "`passwordID`", 0);

  template <typename A>
  const typename pointer_query_columns< ::ApplicationPassword, id_mysql, A >::app_type_
  pointer_query_columns< ::ApplicationPassword, id_mysql, A >::
  app (A::table_name, "`app`", 0);

  template <typename A>
  const typename pointer_query_columns< ::ApplicationPassword, id_mysql, A >::title_type_
  pointer_query_columns< ::ApplicationPassword, id_mysql, A >::
  title (A::table_name, "`title`", 0);

  template <typename A>
  const typename pointer_query_columns< ::ApplicationPassword, id_mysql, A >::url_type_
  pointer_query_columns< ::ApplicationPassword, id_mysql, A >::
  url (A::table_name, "`url`", 0);

  template <typename A>
  const typename pointer_query_columns< ::ApplicationPassword, id_mysql, A >::username_type_
  pointer_query_columns< ::ApplicationPassword, id_mysql, A >::
  username (A::table_name, "`username`", 0);

  template <typename A>
  const typename pointer_query_columns< ::ApplicationPassword, id_mysql, A >::password_type_
  pointer_query_columns< ::ApplicationPassword, id_mysql, A >::
  password (A::table_name, "`password`", 0);

  template <>
  class access::object_traits_impl< ::ApplicationPassword, id_mysql >:
    public access::object_traits< ::ApplicationPassword >
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
      // passwordID
      //
      int passwordID_value;
      my_bool passwordID_null;

      // app
      //
      int app_value;
      my_bool app_null;

      // title
      //
      details::buffer title_value;
      unsigned long title_size;
      my_bool title_null;

      // url
      //
      details::buffer url_value;
      unsigned long url_size;
      my_bool url_null;

      // username
      //
      details::buffer username_value;
      unsigned long username_size;
      my_bool username_null;

      // password
      //
      details::buffer password_value;
      unsigned long password_size;
      my_bool password_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct app_tag;

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

    static const std::size_t column_count = 6UL;
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
  class access::object_traits_impl< ::ApplicationPassword, id_common >:
    public access::object_traits_impl< ::ApplicationPassword, id_mysql >
  {
  };

  // ApplicationPassword
  //
  template <>
  struct alias_traits<
    ::Application,
    id_mysql,
    access::object_traits_impl< ::ApplicationPassword, id_mysql >::app_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::ApplicationPassword, id_mysql >
  {
    // app
    //
    typedef
    odb::alias_traits<
      ::Application,
      id_mysql,
      access::object_traits_impl< ::ApplicationPassword, id_mysql >::app_tag>
    app_alias_;
  };

  template <typename A>
  struct query_columns< ::ApplicationPassword, id_mysql, A >:
    query_columns_base< ::ApplicationPassword, id_mysql >
  {
    // passwordID
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        int,
        mysql::id_long >::query_type,
      mysql::id_long >
    passwordID_type_;

    static const passwordID_type_ passwordID;

    // app
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        int,
        mysql::id_long >::query_type,
      mysql::id_long >
    app_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::Application,
        id_mysql,
        app_alias_ > >
    app_pointer_type_;

    struct app_type_: app_pointer_type_, app_column_type_
    {
      app_type_ (const char* t, const char* c, const char* conv)
        : app_column_type_ (t, c, conv)
      {
      }
    };

    static const app_type_ app;

    // title
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    title_type_;

    static const title_type_ title;

    // url
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    url_type_;

    static const url_type_ url;

    // username
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::basic_string< char >,
        mysql::id_string >::query_type,
      mysql::id_string >
    username_type_;

    static const username_type_ username;

    // password
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    password_type_;

    static const password_type_ password;
  };

  template <typename A>
  const typename query_columns< ::ApplicationPassword, id_mysql, A >::passwordID_type_
  query_columns< ::ApplicationPassword, id_mysql, A >::
  passwordID (A::table_name, "`passwordID`", 0);

  template <typename A>
  const typename query_columns< ::ApplicationPassword, id_mysql, A >::app_type_
  query_columns< ::ApplicationPassword, id_mysql, A >::
  app (A::table_name, "`app`", 0);

  template <typename A>
  const typename query_columns< ::ApplicationPassword, id_mysql, A >::title_type_
  query_columns< ::ApplicationPassword, id_mysql, A >::
  title (A::table_name, "`title`", 0);

  template <typename A>
  const typename query_columns< ::ApplicationPassword, id_mysql, A >::url_type_
  query_columns< ::ApplicationPassword, id_mysql, A >::
  url (A::table_name, "`url`", 0);

  template <typename A>
  const typename query_columns< ::ApplicationPassword, id_mysql, A >::username_type_
  query_columns< ::ApplicationPassword, id_mysql, A >::
  username (A::table_name, "`username`", 0);

  template <typename A>
  const typename query_columns< ::ApplicationPassword, id_mysql, A >::password_type_
  query_columns< ::ApplicationPassword, id_mysql, A >::
  password (A::table_name, "`password`", 0);
}

#include "ApplicationPassword-odb.ixx"

#include <odb/post.hxx>

#endif // APPLICATION_PASSWORD_ODB_HXX
