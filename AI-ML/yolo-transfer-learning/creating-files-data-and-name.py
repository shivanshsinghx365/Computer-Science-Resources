# Creating files labelled_data.data and classes.names
# for training in Darknet framework
#
# Algorithm:
# Setting up full paths --> Reading file classes.txt -->
# --> Creating file classes.names -->
# --> Creating file labelled_data.data
#
# Result:
# Files classes.names and labelled_data.data needed to train
# in Darknet framework

full_path_to_images = 'custom_data'
c = 0

with open(full_path_to_images + '/' + 'classes.names', 'w') as names, \
     open(full_path_to_images + '/' + 'classes.txt', 'r') as txt:
    for line in txt:
        names.write(line)  
        c += 1

with open(full_path_to_images + '/' + 'labelled_data.data', 'w') as data:
    data.write('classes = ' + str(c) + '\n')
    data.write('train = ' + full_path_to_images + '/' + 'train.txt' + '\n')
    data.write('valid = ' + full_path_to_images + '/' + 'test.txt' + '\n')
    data.write('names = ' + full_path_to_images + '/' + 'classes.names' + '\n')
    data.write('backup = backup')