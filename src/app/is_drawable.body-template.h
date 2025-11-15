TEMPLATE_TYPE* as_target_type = (TEMPLATE_TYPE*)test->self;
Drawable* test2 = &(as_target_type->drawable);
if ( test2 == test )
  return true;
return false;
