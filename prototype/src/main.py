import numpy as np
import matplotlib.pyplot as plt

from tools.vector_tools import normalize, reflected
from tools.intersections import nearest_intersected_object

from objects.sphere import Sphere


def main():
    width = 30
    height = 30

    camera = np.array([0, 0, 1])
    ratio = float(width) / height
    screen = (-1, 1 / ratio, 1, -1 / ratio)  # left, top, right, bottom

    objects = [
        Sphere(np.array([0, 0, -1]), 1)
    ]

    image = np.zeros((height, width, 3))
    for i, y in enumerate(np.linspace(screen[1], screen[3], height)):
        for j, x in enumerate(np.linspace(screen[0], screen[2], width)):
            # screen is on origin
            pixel = np.array([x, y, 0])
            origin = camera
            direction = normalize(pixel - origin)

            colour = np.zeros(3)

            # check for intersections
            nearest_object, min_distance = nearest_intersected_object(objects, origin, direction)
            if nearest_object is not None:
                colour = np.array([1, 1, 1])

            image[i, j] = np.clip(colour, 0, 1)
        print("\r%d/%d" % (i + 1, height), end="")

    plt.imsave("../out/image.png", image)
    plt.imshow(image)
    plt.axis("off")
    plt.show()


if __name__ == "__main__":
    main()
