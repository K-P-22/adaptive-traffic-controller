import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Read log data
data = pd.read_csv("traffic_log.csv")

# Set up figure
fig, ax = plt.subplots()
ax.set_xlim(-1, 2)
ax.set_ylim(-1, 2)
ax.axis("off")

# Create two lights (as circles)
north_south = plt.Circle((0.5, 1.5), 0.2, color="gray")
east_west = plt.Circle((1.5, 0.5), 0.2, color="gray")
ax.add_patch(north_south)
ax.add_patch(east_west)

# Map state names to colors
colors = {"GREEN": "green", "YELLOW": "yellow", "RED": "red"}

# Animation function
def update(frame):
    ns_state = data.iloc[frame]["northSouth"]
    ew_state = data.iloc[frame]["eastWest"]
    north_south.set_color(colors.get(ns_state, "gray"))
    east_west.set_color(colors.get(ew_state, "gray"))
    ax.set_title(f"Time: {data.iloc[frame]['time']}s", fontsize=12)
    return north_south, east_west

ani = animation.FuncAnimation(fig, update, frames=len(data), interval=100, repeat=False)

plt.show()
