import os
import requests
from bs4 import BeautifulSoup

def processUrl(url):
    r = requests.get(url)
    data = r.text
    soup = BeautifulSoup(data, "lxml")

    if not os.path.exists('imagesBS'):
        os.mkdir("imagesBS")

    os.chdir("imagesBS")
    with open('urlLinks.txt', mode='w') as urlFile:
        for link in soup.find_all('img'):
            image = link.get("src")
            question_mark = image.find("?")
            image = image[:question_mark]
            image_name = os.path.split(image)[1]
            print(image)
            urlFile.write(image)
            urlFile.write('\n')
            print(image_name)
            r2 = requests.get(image)
            with open(image_name, "wb") as f:
                f.write(r2.content)

        f.close()
    urlFile.close()


def main():
    processUrl("http://pythonforengineers.com/pythonforengineersbook/")

if __name__ == "__main__":
    main()