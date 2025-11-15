TEMPLATE_TYPE* as_target_type = (TEMPLATE_TYPE*)test->self;
Cloneable* test2 = &(as_target_type->cloneable);
if ( test2 == test )
  return true;
return false;
