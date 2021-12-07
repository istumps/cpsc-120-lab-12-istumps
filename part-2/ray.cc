
#include "ray.h"

[[nodiscard]] Point3 Ray::origin() const {
  return origin_; 
  // TODO: Implement this member function given the documentation in ray.h
}

[[nodiscard]] Vec3 Ray::direction() const {
  return direction_; 
  // TODO: Implement this member function given the documentation in ray.h
}

[[nodiscard]] Point3 Ray::at(double t) const {
  return origin_ + (t * direction_); 
  // TODO: Implement this member function given the documentation in ray.h
}

std::ostream& operator<<(std::ostream& out, const Ray& r) {

  
// TODO: Implement this member function given the documentation in ray.h
out << "Ray(origin=" << r.origin() << ", direction=" << r.direction() << ")";
  return out;
}
