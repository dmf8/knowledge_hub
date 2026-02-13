from pathlib import Path

# 1. special paths
pHome = Path.home()
pCwd = Path.cwd()

# 2. create path
p1 = Path(".")/"empty.txt"
p2 = Path.cwd()/"test_pathlib.py"
p3 = Path(".")/"test_pathlib.py"
p4 = Path.cwd()

# 3. abs
# print("abs:")
# print(p1.resolve())
# print(p2.resolve())
# print(p3.resolve())

# 4. assertions
print("exist:")
print(p1.exists())
print(p2.exists())
print(p4.exists())

# 5. parts
print(p1.parts)
print(p2.parts)
print(p4.parts)

# print("abs:")
# print(pHome.resolve())
# # print(pHome.absolute())
# print(pCwd.resolve())

# print(f"\nparts:")
# print(pCwd.parts)
