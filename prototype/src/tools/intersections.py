import numpy as np

from objects.sphere import Sphere

def nearest_intersected_object(objects, ray_origin, ray_direction):
    distances = []
    
    for o in objects:
        if isinstance(o, Sphere):
            distances.append(o.intersect(ray_origin, ray_direction))
        else:
            print("object not supported")

    
    nearest_object = None
    min_distance = np.inf
    for index, distance in enumerate(distances):
        if distance and distance < min_distance:
            min_distance = distance
            nearest_object = objects[index]
    return nearest_object, min_distance