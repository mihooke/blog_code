import os
def scienceRowsInSingleFile(file):
    count = 0
    # 统计单个文件中的非空行数
    with open(file, 'r') as f:
        for line in f:
            if line.split():
                count += 1
    return count

rows = 0
postfix = ('.h', '.cpp', '.pro', '.json')


# 递归遍历
def ergodicDir(dirs):
    fileDirList = os.listdir(dirs)
    print(fileDirList)
    
    for path in fileDirList:
        paths = os.path.join(dirs, path)
        if os.path.isfile(paths):
            if os.path.splitext(paths)[1] in postfix:
                print(paths)
                global rows
                rows += scienceRowsInSingleFile(paths)
        else:
            ergodicDir(paths)
    return rows