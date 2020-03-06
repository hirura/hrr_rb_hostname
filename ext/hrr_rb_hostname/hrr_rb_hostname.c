#include "hrr_rb_hostname.h"

#define HRR_RB_HOSTNAME_MAX 1024

VALUE rb_mHrrRbHostname;

VALUE
hrr_rb_hostname_gethostname(void)
{
  char name[HRR_RB_HOSTNAME_MAX + 1];

  name[HRR_RB_HOSTNAME_MAX] = '\0';

  if (gethostname(name, HRR_RB_HOSTNAME_MAX) < 0)
    rb_sys_fail("gethostname");

  return rb_str_new_cstr(name);
}

VALUE
hrr_rb_hostname_sethostname(VALUE self, VALUE arg)
{
  char *name;

  name = StringValueCStr(arg);

  if (sethostname(name, strlen(name)) < 0)
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
