from bs4 import BeautifulSoup
import urllib.request


def htmlRetrieve(siteUrl):
    userAgent = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.5112.79 Safari/537.36"
    headers = {'User-Agent': userAgent}

    request = urllib.request.Request(siteUrl, None, headers)
    response = urllib.request.urlopen(request)
    websiteData = response.read()
    return websiteData


def preparingData(rawWebData):
    soup = BeautifulSoup(rawWebData, 'html5lib')
    relevantData = soup.find_all('td')
    return relevantData


def parsingData(table):
    # Create list for all the data
    data = []
    for x in range(0, 20):
        data.append([])

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

    data[0].append(columnNames)

    # playerID and playerName
    playerID = 1
    for x in table:
        player = x.find('a')
        if player is None:
            continue
        else:
            player = str(player).split("title=")[1]
            player = player[1:]
            player = player.split(" Stats")[0]
            data[1].append(playerID)
            playerID += 1
            data[2].append(player)

    # All data
    for x in range(0, len(table)):
        player = table[x].find('a')
        if player is None:
            continue
        else:
            byeWeek = table[x + 1]
            byeWeek = str(byeWeek).split('>')[1]
            byeWeek = byeWeek.split('<')[0]
            data[3].append(byeWeek)

            passingAtt = table[x + 3]
            passingAtt = str(passingAtt).split('>')[1]
            passingAtt = passingAtt.split('<')[0]
            data[4].append(passingAtt)

            passingCmp = table[x + 4]
            passingCmp = str(passingCmp).split('>')[1]
            passingCmp = passingCmp.split('<')[0]
            data[5].append(passingCmp)

            passingYds = table[x + 5]
            passingYds = str(passingYds).split('>')[1]
            passingYds = passingYds.split('<')[0]
            data[6].append(passingYds)

            passingTD = table[x + 6]
            passingTD = str(passingTD).split('>')[1]
            passingTD = passingTD.split('<')[0]
            data[7].append(passingTD)

            passingInt = table[x + 7]
            passingInt = str(passingInt).split('>')[1]
            passingInt = passingInt.split('<')[0]
            data[8].append(passingInt)

            passing2pt = table[x + 8]
            passing2pt = str(passing2pt).split('>')[1]
            passing2pt = passing2pt.split('<')[0]
            data[9].append(passing2pt)

            rushingAtt = table[x + 9]
            rushingAtt = str(rushingAtt).split('>')[1]
            rushingAtt = rushingAtt.split('<')[0]
            data[10].append(rushingAtt)

            rushingYds = table[x + 10]
            rushingYds = str(rushingYds).split('>')[1]
            rushingYds = rushingYds.split('<')[0]
            data[11].append(rushingYds)

            rushingTD = table[x + 11]
            rushingTD = str(rushingTD).split('>')[1]
            rushingTD = rushingTD.split('<')[0]
            data[12].append(rushingTD)

            rushing2pt = table[x + 12]
            rushing2pt = str(rushing2pt).split('>')[1]
            rushing2pt = rushing2pt.split('<')[0]
            data[13].append(rushing2pt)

            receivingRec = table[x + 13]
            receivingRec = str(receivingRec).split('>')[1]
            receivingRec = receivingRec.split('<')[0]
            data[14].append(receivingRec)

            receivingYds = table[x + 14]
            receivingYds = str(receivingYds).split('>')[1]
            receivingYds = receivingYds.split('<')[0]
            data[15].append(receivingYds)

            receivingTD = table[x + 15]
            receivingTD = str(receivingTD).split('>')[1]
            receivingTD = receivingTD.split('<')[0]
            data[16].append(receivingTD)

            receiving2pt = table[x + 16]
            receiving2pt = str(receiving2pt).split('>')[1]
            receiving2pt = receiving2pt.split('<')[0]
            data[17].append(receiving2pt)

            fumbleLost = table[x + 17]
            fumbleLost = str(fumbleLost).split('>')[1]
            fumbleLost = fumbleLost.split('<')[0]
            data[18].append(fumbleLost)

            fumbleTD = table[x + 18]
            fumbleTD = str(fumbleTD).split('>')[1]
            fumbleTD = fumbleTD.split('<')[0]
            data[19].append(fumbleTD)

    return data


url = 'https://www.footballdb.com/fantasy-football/index.html?yr=2024&pos=OFF&wk=all&key=48ca46aa7d721af4d58dccc0c249a1c4'
siteData = htmlRetrieve(url)
table = preparingData(siteData)
data = parsingData(table)


