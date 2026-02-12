from pathlib import Path

cwd = Path.cwd()
print(cwd.resolve().as_posix()+"/abc")
