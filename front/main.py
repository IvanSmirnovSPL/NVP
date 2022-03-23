import matplotlib.pyplot as plt
import os
import shutil
import pathlib
from pathlib import Path




def main():

    home = Path(Path.cwd().parent.parent, "front")
    rez_path = Path(home, 'rez')
    shutil.rmtree(rez_path, ignore_errors=True)
    os.mkdir(rez_path)
    exp_path = Path(home, 'exp')

    def draw_solution(name_plot, x_a, y_a, x, y):
        plt.scatter(x, y, c='r', label='numeric_' + name_plot)
        plt.plot(x_a, y_a, c='b', label='analytic_' + name_plot)
        plt.legend()
        plt.grid(True)
        plt.savefig(Path(rez_path, name_plot + '.png'), dpi=100)
        plt.cla()



    f_a = open(Path(exp_path, 'exact_solution.dat'), 'r')
    f = open(Path(exp_path, 'solution.dat'), 'r')


    class Data:
        def __init__(self):
            self.p = []
            self.rho = []
            self.v = []
            self.time = []


    data = Data()

    for line in f:
        tmp = list(map(float, line.split()))
        data.time.append(tmp[0])
        data.rho.append(tmp[1])
        data.v.append(tmp[2])
        data.p.append(tmp[3])

    a_data = Data()

    for line in f_a:
        tmp = list(map(float, line.split()))
        a_data.time.append(tmp[0])
        a_data.rho.append(tmp[1])
        a_data.v.append(tmp[2])
        a_data.p.append(tmp[3])

    names = ['density', 'velocity', 'pressure']
    draw_solution('density', a_data.time, a_data.rho, data.time, data.rho)
    draw_solution('velocity', a_data.time, a_data.v, data.time, data.v)
    draw_solution('pressure', a_data.time, a_data.p, data.time, data.p)


if __name__ == "__main__":
    main()
