

import os
  
parent_dir = os.path.dirname(os.path.abspath(__file__))

data = '''Artichoke, 6.5 ,  7.5, 560 ,  1260, 15, 25, 30, 60
Asparagus, 6 ,  6.8, 980 ,  1200, 15, 25, 240, 330
Bawang daun, 6.5 ,  7, 980 ,  1260, 18, 25, 55, 75
Bayam, 6 ,  7, 1260 ,  1610, 25, 30, 25, 30
Brokoli, 6 ,  6.8, 1960 ,  2450, 21, 32, 60, 95
Brussell kecambah, 6.5, 6.5, 1750 ,  2100, 15, 25, 70, 95
Endive, 5.5, 5.5, 1400 ,  1680, 15, 18, 50, 85
Kailan, 5.5 ,  6.5, 1050 ,  1400, 22, 35, 40, 56
Kangkung, 5.5 ,  6.5, 1050 ,  1400, 25, 30, 20, 30
Kubis, 6.5 ,  7, 1750 ,  2100, 19, 21, 80,115
Kubis bunga, 6.5 ,  7, 1750 ,  2100, 25, 30, 47, 63
Pakcoy, 7, 7, 1050 ,  1400, 23, 30, 30, 45
Caisim, 5.5 ,  6.5, 1050 ,  1400, 25, 30, 21, 38
Sawi pahit, 6 ,  6.5, 840 ,  1680, 19, 21, 65, 70
Sawi pagoda (tatsoi), 5.5 ,  6.5, 1050 ,  1400, 18, 25, 25, 45
Seledri, 6.5, 6.5, 1260 ,  1680, 15, 24, 24, 100
Selada, 6 ,  7, 560 ,  840, 23, 25, 45, 85
Silverbeet, 6 ,  7, 1260 ,  1610, 16, 18, 45, 65
Buncis, 6, 8, 1400 ,  2800, 20, 25, 45, 50
Cabai, 6 ,  6.5, 1260 ,  1540, 18, 30, 60, 90
Kacang polong, 6 ,  7, 980 ,  1260, 28, 32, 80, 100
Kembang kol, 6 ,  7, 1050 ,  1400, 28, 32, 45, 75
Okra, 6.5, 6.5, 1400 ,  1680, 28, 32, 65, 95
Paprika, 6 ,  6.5, 1260 ,  1540, 21, 27, 75, 95
Tomat, 6 ,  6.5, 1400 ,  3500, 24, 32, 60, 90
Terong, 6, 8, 1750 ,  2450, 22, 30, 65, 85
Timun, 5.5, 5.5, 1190 ,  1750, 20, 32, 32, 47
Timun jepang, 6, 8, 1260 ,  1680, 18, 30, 75, 115
Blueberry, 4 ,  5, 1260 ,  1400, 23, 33, 1095, 1825
Kismis hitam, 6, 8, 980 ,  1260, 24, 27, 45, 255
Kismis merah, 6, 8, 1400 ,  1680, 23, 34, 45, 275
Labu, 5.5 ,  7.5, 1260 ,  1680, 18, 27, 60, 90
Melon, 5.5 ,  6, 1400 ,  1750, 25, 30, 65, 75
Markisa, 6.5, 6.5, 840 ,  1680, 20, 30, 270, 450
Nanas, 5.5 ,  6, 1400 ,  1680, 21, 28, 365, 730
Pisang, 5.5 ,  6, 1260 ,  1540, 15, 35, 365, 731
Pepaya, 6.5, 6.5, 840 ,  1680, 25, 30, 180, 360
Strawberry, 6, 8, 1260 ,  1540, 17, 20, 90, 240
Semangka, 5.8, 5.8, 1260 ,  1680, 20, 30, 58, 75
African violet, 6 ,  7, 840 ,  1050, 16, 32, 45, 495
Anthurium, 5 ,  6, 1120 ,  1400, 23, 40, 45, 515
Aphelandra, 5 ,  6, 1260 ,  1680, 16, 33, 45, 535
Aster, 6 ,  6.5, 1260 ,  1680, 23, 41, 45, 555
Begonia, 6.5, 6.5, 980 ,  1260, 16, 34, 45, 575
Bromeliads, 5 ,  7.5, 560 ,  840, 23, 42, 45, 595
Caladium, 6 ,  7.5, 1120 ,  1400, 16, 35, 45, 615
Canna, 6, 8, 1260 ,  1680, 23, 43, 45, 635
Carnation, 6, 8, 1260 ,  1680, 16, 36, 45, 655
Chrysanthemum (Krisan), 6 ,  6.2, 1400 ,  1750, 23, 44, 45, 675
Cymbidiums, 5.5, 5.5, 420 ,  560, 16, 37, 45, 695
Dahlia, 6 ,  7, 1050 ,  1400, 23, 45, 45, 715
Dieffenbachia, 5, 5, 1400 ,  1680, 16, 38, 45, 735
Cracaena, 5 ,  6, 1400 ,  1680, 23, 46, 45, 755
Ferns, 6, 8, 1120 ,  1400, 16, 39, 45, 775
Ficus, 5.5 ,  6, 1120 ,  1400, 23, 47, 45, 795
Freesia, 6.5, 6.5, 700 ,  1400, 16, 40, 45, 815
Impatiens, 5.5 ,  6.5, 1260 ,  1400, 23, 48, 45, 835
Gerbera, 5 ,  6.5, 1400 ,  1750, 16, 41, 45, 855
Gladiolus, 5.5 ,  6.5, 1400 ,  1680, 23, 49, 45, 875
Monstera, 5 ,  6, 1400 ,  1680, 16, 42, 45, 895
Palms, 6 ,  7.5, 1120 ,  1400, 23, 50, 45, 915
Roses (mawar), 5.5 ,  6, 1050 ,  1750, 16, 43, 45, 935
Stock, 6 ,  7, 1120 ,  1400, 23, 51, 45, 955
Basil (kemangi), 5.5 ,  6.5, 700 ,  1120, 7, 27, 42, 48
Chicory, 5.5 ,  6, 1400 ,  1600, 15, 18, 50, 85
Chives, 6 ,  6.5, 1260 ,  1540, 16, 27, 45, 65
Fennel, 6.4 ,  6.8, 700 ,  980, 22, 25, 210, 260
Lavender, 6.4 ,  6.8, 700 ,  980, 16, 27, 360, 480
Lemon balm, 5.5 ,  6.5, 700 ,  1120, 22, 28, 120, 150
Marjoram, 6, 8, 1120 ,  1400, 15, 20, 67, 105
Mint, 5.5 ,  6, 1400 ,  1680, 22, 30, 120, 150
Mustard cress, 6 ,  6.5, 840 ,  1680, 23, 28, 35, 75
Parsley, 5.5 ,  6, 560 ,  1260, 23, 28, 70, 95
Rosemary, 5.5 ,  6, 700 ,  1120, 10, 27, 65, 115
Sage, 5.5 ,  6.5, 700 ,  1120, 15, 21, 75, 95
Thyme, 5.5 ,  7, 560 ,  1120, 16, 27, 70, 85
Watercress, 6.5 ,  6.8, 280 ,  1260, 8, 15, 90, 120
Bawang merah, 6 ,  6.7, 980 ,  1260, 25, 32, 55, 90
Bawang putih, 6, 8, 980 ,  1260, 15, 25, 90, 120
Kentang, 5 ,  6, 1400 ,  1750, 17, 21, 80, 120
Lobak, 6 ,  6.5, 1260 ,  1680, 15, 21, 23, 70
Talas, 5 ,  5.5, 1750 ,  2100, 25, 30, 210, 300
Ubi, 6, 8, 980 ,  1260, 25, 28, 90, 180
Ubi jalar, 5.5 ,  6, 1400 ,  1750, 25, 30, 90, 181
Wortel, 6.3, 6.3, 1120 ,  1400, 15, 21, 60, 85'''

plants = data.split('\n')
for index, plant in enumerate(plants):
    plant = plant.replace(" ","")
    data = plant.split(',')

    # directory = str(index)
    # path = os.path.join(parent_dir, directory)
    # os.mkdir(path)

    if len(data) < 9:
        print(index)
    if data[2] == data[1]:
        data[2] = float(data[2]) + 2 
        print(index)

    # f = open('./' + str(index) + '/name.txt', "w")
    # f.write(data[0])
    # f.close()

    # f = open('./' + str(index) + '/ph-low.txt', "w")
    # f.write(data[1])
    # f.close()

    # f = open('./' + str(index) + '/ph-high.txt', "w")
    # f.write(str(data[2]))
    # f.close()
    
    # f = open('./' + str(index) + '/ppm-low.txt', "w")
    # f.write(str(data[3]))
    # f.close()
    
    # f = open('./' + str(index) + '/ppm-high.txt', "w")
    # f.write(str(data[4]))
    # f.close()
    
    # f = open('./' + str(index) + '/tmp-low.txt', "w")
    # f.write(str(data[5]))
    # f.close()
    
    # f = open('./' + str(index) + '/tmp-high.txt', "w")
    # f.write(str(data[6]))
    # f.close()
    
    f = open(parent_dir + '/database/' + str(index) + '/dur-low.txt', "w")
    f.write(str(data[7]))
    f.close()
    
    # f = open('./' + str(index) + '/dur-high.txt', "w")
    # f.write(str(data[8]))
    # f.close()
