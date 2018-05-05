
def deleteComment(file):
    with open(file, 'r') as f:
        lines = ""
        three_double_quota_count = 0
        three_single_quota_count = 0
        all_context = f.readlines()
        for i,line in enumerate(all_context):
            if (i > len(all_context)-2):
                break
            idx = line.find("#")
            if idx == 0:
                continue
            elif idx > 0:
                line = line[:idx] + "\n"
                
            idx_quota = line.find(r'"""')
            if idx_quota >= 0:
                three_double_quota_count += 1
                continue
            else:
                if three_double_quota_count % 2 == 1:
                    continue
            
            idx_quota = line.find(r"'''")
            if idx_quota >= 0:
                three_single_quota_count += 1
                continue
            else:
                if three_single_quota_count % 2 == 1:
                    continue
            lines += line
    with open(file, "w") as f:
        f.write(lines)

if __name__ == "__main__":
    deleteComment("E:\\python\\MyStudy\\poll2.py")
    print("finished!")
