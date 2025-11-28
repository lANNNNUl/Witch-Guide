
import random
import matplotlib.pyplot as plt

# 1. 生成 10 个 1-100 的随机整数
nums = [random.randint(1, 100) for _ in range(10)]
print("原始:", nums)

# 2. 排序
nums.sort()
print("排序后:", nums)

# 3. 画折线图
plt.plot(nums, marker='o')
plt.title("Random Sorted Line")
plt.xlabel("Index")
plt.ylabel("Value")
plt.grid(True)
plt.savefig("sorted.png")   # 生成图片文件
print("已保存折线图 → sorted.png")