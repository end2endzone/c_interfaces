TEMPLATE_TYPE* as_target_type = (TEMPLATE_TYPE*)test->self;
Resizable* test2 = &(as_target_type->resizable);
if ( test2 == test )
  return true;
return false;
