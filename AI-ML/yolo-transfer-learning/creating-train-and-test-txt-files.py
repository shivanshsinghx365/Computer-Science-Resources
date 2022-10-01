# Creating files train.txt and test.txt
# for training in Darknet framework
#
# Algorithm:
# Setting up full paths --> List of paths -->
# --> Extracting 15% of paths to save into test.txt file -->
# --> Writing paths into train and test txt files
#
# Result:
# Files train.txt and test.txt with full paths to images

import os

full_path_to_images = 'custom_data'
os.chdir(full_path_to_images)
p = []

for current_dir, dirs, files in os.walk('.'):
    for f in files:
        if f.endswith('.jpg'):
            path_to_save_into_txt_files = full_path_to_images + '/' + f
            p.append(path_to_save_into_txt_files + '\n')

p_test = p[:int(len(p) * 0.15)]

p = p[int(len(p) * 0.15):]
with open('train.txt', 'w') as train_txt:
    for e in p:
        train_txt.write(e)

with open('test.txt', 'w') as test_txt:
    for e in p_test:
        test_txt.write(e)