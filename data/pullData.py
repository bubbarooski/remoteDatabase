import urllib.request
import csv
from bs4 import BeautifulSoup


# This function is used to retrieve the raw HTML from the website containing player data
def htmlRetrieve(siteUrl):
    userAgent = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.79 Safari/537.36"
    headers = {'User-Agent': userAgent}

    request = urllib.request.Request(siteUrl, None, headers)
    response = urllib.request.urlopen(request)
    websiteData = response.read()
    return websiteData


# This function is used to pass the HTML into the BeautifulSoup library to make easier to work with
def preparingData(rawWebData):
    soup = BeautifulSoup(rawWebData, 'html5lib')
    relevantData = soup.find_all('td')
    return relevantData


# This function is used to parse the "pretty" data and return lists of all relevant data
def parsingData(table):

    data = []
    playerID = 1
    for x in range(0, len(table)):
        player = table[x].find('a')
        if player is None:
            continue
        else:
            temp = []
            player = str(player).split("title=")[1]
            player = player[1:]
            player = player.split(" Stats")[0]
            temp.append(playerID)
            playerID += 1
            temp.append(player)

            byeWeek = table[x + 1]
            byeWeek = str(byeWeek).split('>')[1]
            byeWeek = byeWeek.split('<')[0]
            temp.append(byeWeek)

            passingAtt = table[x + 3]
            passingAtt = str(passingAtt).split('>')[1]
            passingAtt = passingAtt.split('<')[0]
            temp.append(passingAtt)

            passingCmp = table[x + 4]
            passingCmp = str(passingCmp).split('>')[1]
            passingCmp = passingCmp.split('<')[0]
            temp.append(passingCmp)

            passingYds = table[x + 5]
            passingYds = str(passingYds).split('>')[1]
            passingYds = passingYds.split('<')[0]
            temp.append(passingYds)

            passingTD = table[x + 6]
            passingTD = str(passingTD).split('>')[1]
            passingTD = passingTD.split('<')[0]
            temp.append(passingTD)

            passingInt = table[x + 7]
            passingInt = str(passingInt).split('>')[1]
            passingInt = passingInt.split('<')[0]
            temp.append(passingInt)

            passing2pt = table[x + 8]
            passing2pt = str(passing2pt).split('>')[1]
            passing2pt = passing2pt.split('<')[0]
            temp.append(passing2pt)

            rushingAtt = table[x + 9]
            rushingAtt = str(rushingAtt).split('>')[1]
            rushingAtt = rushingAtt.split('<')[0]
            temp.append(rushingAtt)

            rushingYds = table[x + 10]
            rushingYds = str(rushingYds).split('>')[1]
            rushingYds = rushingYds.split('<')[0]
            temp.append(rushingYds)

            rushingTD = table[x + 11]
            rushingTD = str(rushingTD).split('>')[1]
            rushingTD = rushingTD.split('<')[0]
            temp.append(rushingTD)

            rushing2pt = table[x + 12]
            rushing2pt = str(rushing2pt).split('>')[1]
            rushing2pt = rushing2pt.split('<')[0]
            temp.append(rushing2pt)

            receivingRec = table[x + 13]
            receivingRec = str(receivingRec).split('>')[1]
            receivingRec = receivingRec.split('<')[0]
            temp.append(receivingRec)

            receivingYds = table[x + 14]
            receivingYds = str(receivingYds).split('>')[1]
            receivingYds = receivingYds.split('<')[0]
            temp.append(receivingYds)

            receivingTD = table[x + 15]
            receivingTD = str(receivingTD).split('>')[1]
            receivingTD = receivingTD.split('<')[0]
            temp.append(receivingTD)

            receiving2pt = table[x + 16]
            receiving2pt = str(receiving2pt).split('>')[1]
            receiving2pt = receiving2pt.split('<')[0]
            temp.append(receiving2pt)

            fumbleLost = table[x + 17]
            fumbleLost = str(fumbleLost).split('>')[1]
            fumbleLost = fumbleLost.split('<')[0]
            temp.append(fumbleLost)

            fumbleTD = table[x + 18]
            fumbleTD = str(fumbleTD).split('>')[1]
            fumbleTD = fumbleTD.split('<')[0]
            temp.append(fumbleTD)

            data.append(temp)

    return data


# This function is used to write the parsed data to a csv file
def writingData(playerData):
    columnNames = [
        'playerID',
        'playerName',
        'byeWeek',
        'passingAtt',
        'passingCmp',
        'passingYds',
        'passingTD',
        'passingInt',
        'passing2pt',
        'rushingAtt',
        'rushingYds',
        'rushingTD',
        'rushing2pt',
        'receivingRec',
        'receivingYds',
        'receivingTD',
        'receiving2pt',
        'fumbleLost',
        'fumbleTD'
    ]

    playerData.insert(0, columnNames)

    with open('playerData.csv', 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(playerData)


# Called to control the entire process of creating the CSV of player data
def dataDriver():
    url = 'https://www.footballdb.com/fantasy-football/index.html?yr=2024&pos=OFF&wk=all&key=48ca46aa7d721af4d58dccc0c249a1c4'
    siteData = htmlRetrieve(url)
    table = preparingData(siteData)
    data = parsingData(table)
    writingData(data)


dataDriver()
