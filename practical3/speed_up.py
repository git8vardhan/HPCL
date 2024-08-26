import matplotlib.pyplot as plt

# Data
matrix_sizes = [250, 500, 750, 1000, 2000]
threads = [1, 2, 4, 8]

# Times in seconds
times = {
    250: [0.000156, 0.000221, 0.000156, 0.000195],
    500: [0.000832, 0.000717, 0.000790, 0.005586],
    750: [0.001603, 0.000905, 0.001019, 0.003646],
    1000: [0.002545, 0.001425, 0.000824, 0.000933],
    2000: [0.010269, 0.006010, 0.003288, 0.003321]
}

# Calculate speedup
def calculate_speedup(times):
    speedup = {}
    for size, t in times.items():
        speedup[size] = [t[0] / time for time in t]
    return speedup

speedup = calculate_speedup(times)

# Plotting
plt.figure(figsize=(12, 8))

for size in matrix_sizes:
    plt.plot(threads, speedup[size], marker='o', label=f'{size}x{size}')

plt.xlabel('Number of Threads')
plt.ylabel('Speed Up')
plt.title('Speedup vs Number of Threads for Different Matrix Sizes')
plt.legend()
plt.grid(True)
plt.xscale('log')
plt.yscale('log')


plt.show()
