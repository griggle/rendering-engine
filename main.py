import os
import sys

import numpy as np
from plyfile import PlyData

os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"
import pygame


def main():
    plydata = PlyData.read('res/shark.ply')

    screen_width = 1200
    screen_height = 900

    pygame.init()
    window = pygame.display.set_mode((screen_width, screen_height))

    clock = pygame.time.Clock()

    frame = 0

    while True:
        # Handle events
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        # Set background color to our window
        window.fill("black")

        nvertices = len(plydata['vertex'])
        nfaces = len(plydata['face'])

        # Copy vertex positions into numpy array
        V = np.empty((3, nvertices))
        V[0, :] = plydata['vertex']['x']
        V[1, :] = plydata['vertex']['y']
        V[2, :] = plydata['vertex']['z']

        F = np.vstack(plydata['face'].data['vertex_indices'])

        R = np.array([[0.9063, 0.0, 0.4226], [0.0, -1.0000, 0.0], [0.4226, 0, -0.9063]])
        t = np.array([[1.0350], [0.3861], [15.0140]])
        K = np.array([[2290.0, 0.0, 250.0], [0.0, 2290.0, 163.0], [0.0, 0.0, 1.0]])

        # Perform perspective projection
        hV = np.vstack((V, np.ones(len(V[0]))))
        hRt = np.vstack((np.hstack((R, t)), [0, 0, 0, 1]))
        hK = np.hstack((K, [[0], [0], [0]]))
        ProjM = np.matmul(hK, hRt)

        theta = 0.01 * frame
        ry = np.array([[np.cos(theta), 0, np.sin(theta), 0],
                       [0, 1, 0, 0],
                       [-np.sin(theta), 0, np.cos(theta), 0],
                       [0, 0, 0, 1]])

        hu = np.matmul(ProjM, np.matmul(ry, hV))
        u = hu / hu[2]

        u[1, :] += 250
        u[0, :] += 200

        for i in range(nfaces):
            pygame.draw.polygon(window, (100, 100, 100), [([u[0, F[i, 0]], u[1, F[i, 0]]]),
                                                          ([u[0, F[i, 1]], u[1, F[i, 1]]]),
                                                          ([u[0, F[i, 2]], u[1, F[i, 2]]])], width=0)

            pygame.draw.line(window, (255, 255, 255), ([u[0, F[i, 0]], u[1, F[i, 0]]]),
                             ([u[0, F[i, 1]], u[1, F[i, 1]]]))
            pygame.draw.line(window, (255, 255, 255), ([u[0, F[i, 0]], u[1, F[i, 0]]]),
                             ([u[0, F[i, 2]], u[1, F[i, 2]]]))
            pygame.draw.line(window, (255, 255, 255), ([u[0, F[i, 1]], u[1, F[i, 1]]]),
                             ([u[0, F[i, 2]], u[1, F[i, 2]]]))

        for i in range(len(u[0])):
            window.set_at((int(u[0, i]), int(u[1, i])), (255, 0, 255))

        # Display world
        pygame.display.flip()

        clock.tick(30)

        frame = frame + 1


if __name__ == "__main__":
    main()
