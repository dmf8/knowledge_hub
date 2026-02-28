from pathlib import Path
from pathlib import PureWindowsPath
import sys

# 1. special paths
pHome = Path.home()
pCwd = Path.cwd()

# 2. create path
pDirRoot = Path("/")
pDirCur = Path.cwd()
pDirDot = Path(".")
pDirDotDot = Path("..")
pDirNotExist = Path("test")
pDirNotExist1 = Path("test/")

pLnkNotExist = Path(".")/"test_files/lxyz"
pLnkExist = Path(".")/"test_files/labc"
pFileNotExist = Path(".")/"test_files/null"
pFileNoPermission = Path(".")/"test_files/000"
pDriver1 = Path("/")
pDriver2 = Path("C:")
pDriverFile = Path("C:/abc")

# 3. abs
# print("abs:")
# print(p1.resolve())
# print(p2.resolve())
# print(p3.resolve())

# 4. assertions
# print(f"pDirRoot: {pDirRoot.is_file()}")
# print(f"pDirCur: {pDirCur.is_file()}")
# print(f"pDirDot: {pDirDot.is_file()}")
# print(f"pDirDotDot: {pDirDotDot.is_file()}")
# print(f"pDirNotExist: {pDirNotExist.is_file()}")
# print(f"pDirNotExist1: {pDirNotExist1.is_file()}")


try:
    print(pDriver1.stat())
    print(pDriver2.stat())
# except FileNotFoundError:
#     print("FileNotFoundError")
except Exception as e:
    print(str(e))
    print(type(e).__name__)
    print(e.args)
else:
    print("no except")
finally:
    print("final")
# print(pDriverFile.stat())
# print("stat error")

# print("abs:")
# print(pHome.resolve())
# # print(pHome.absolute())
# print(pCwd.resolve())

# print(f"\nparts:")
# print(pCwd.parts)
