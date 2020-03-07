#include "hrr_rb_hostname.h"

#define HRR_RB_HOSTNAME_MAX 1024

VALUE rb_mHrrRbHostname;

/*
 * A wrapper around gethostname. Returns hostname that is set on the machine.
 *
 * @raise [Errno::EINVAL] when the name is too long.
 * @return [String] hostname that is set on the machine.
 */
VALUE
hrr_rb_hostname_gethostname(void)
{
  char name[HRR_RB_HOSTNAME_MAX + 1];

  name[HRR_RB_HOSTNAME_MAX] = '\0';

  if (gethostname(name, HRR_RB_HOSTNAME_MAX) < 0)
    rb_sys_fail("gethostname");

  return rb_str_new_cstr(name);
}

/*
 * A wrapper around sethostname. Returns hostname that is updated on the machine.
 *
 * @param [String] name hostname to be set
 * @raise [Errno::EFAULT] when the name pointed outside of user address space.
 * @raise [Errno::EINVAL] when the name is too long.
 * @raise [Errno::EPERM ] when the caller did not have the CAP_SYS_ADMIN capability in the user namespace associated with its UTS namespace (see namespaces(7)).
 * @return [String] hostname that is updated on the machine
 */
VALUE
hrr_rb_hostname_sethostname(VALUE self, VALUE name)
{
  char *hname = StringValueCStr(name);

  if (sethostname(hname, strlen(hname)) < 0)
    rb_sys_fail("sethostname");

  return hrr_rb_hostname_gethostname();
}

void
Init_hrr_rb_hostname(void)
{
  rb_mHrrRbHostname = rb_define_module("HrrRbHostname");
  rb_define_singleton_method(rb_mHrrRbHostname, "get",         hrr_rb_hostname_gethostname, 0);
  rb_define_singleton_method(rb_mHrrRbHostname, "gethostname", hrr_rb_hostname_gethostname, 0);
  rb_define_singleton_method(rb_mHrrRbHostname, "set",         hrr_rb_hostname_sethostname, 1);
  rb_define_singleton_method(rb_mHrrRbHostname, "sethostname", hrr_rb_hostname_sethostname, 1);
}
