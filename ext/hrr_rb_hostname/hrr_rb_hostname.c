#include "hrr_rb_hostname.h"

VALUE rb_mHrrRbHostname;

void
Init_hrr_rb_hostname(void)
{
  rb_mHrrRbHostname = rb_define_module("HrrRbHostname");
}
