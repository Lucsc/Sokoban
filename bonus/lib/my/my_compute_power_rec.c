/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** my_compute_power_rec.c
*/

int my_compute_power_rec(int nb, int p)
{
    int cmpt;

    if (cmpt > 2147483647)
        return (0);
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    cmpt = nb * my_compute_power_rec(nb, p - 1);
    return (cmpt);
}
