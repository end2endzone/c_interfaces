TEMPLATE_TYPE* as_target_type = (TEMPLATE_TYPE*)test->self;
Shape* test2 = &(as_target_type->shape);
if ( test2 == test )
  return true;
return false;
