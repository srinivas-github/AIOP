import urllib.request
import re
import os
from os.path import basename
from urllib.parse import urlsplit
from urllib.parse import urlparse
from posixpath import basename,dirname

def process_url(raw_url):
    if ' ' not in raw_url[-1]:
        raw_url=raw_url.replace(' ','%20')
        return raw_url
    elif ' ' in raw_url[-1]:
        raw_url=raw_url[:-1]
        raw_url=raw_url.replace(' ','%20')
        return raw_url

def grabImages(url):
    parse_object = urlparse(url)
    print("parse_object.path: ", parse_object.path)
    imgdir = basename(parse_object.path)
    #print("dirname:", imgdir)
    if imgdir is '':
        imgdir = 'demo'

    if not os.path.exists('images'):
        os.mkdir("images")

    if not os.path.exists("images/"+imgdir):
        os.mkdir("images/"+imgdir)

    os.chdir("images/"+imgdir)

    user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.7) Gecko/2009021910 Firefox/3.0.7'
    headers = {'User-Agent': user_agent}
    request = urllib.request.Request(url, None, headers)
    urlcontent = urllib.request.urlopen(request).read()

    #write the image data to the disk
    imgurls = re.findall('img .*?src="(.*?)"',urlcontent.decode('utf=8'))
    for imgurl in imgurls:
        try:
            imgurl = process_url(imgurl)
            print("imageUrl: ", imgurl)
            imgdata = urllib.request.urlopen(imgurl).read()
            filename = basename(urlsplit(imgurl)[2])
            print ("filename", filename)
            output = open(filename,'wb')
            output.write(imgdata)
            output.close()

        except:
             pass

    #Write the urls to the disk file
    with open('urlLinks.txt', mode='wt', encoding='utf-8') as urlFile:
        urlLinks = re.findall('img .*?src="(.*?)"', urlcontent.decode('utf-8'))
        for urlLink in urlLinks:
            urlFile.write(urlLink)
            urlFile.write('\n')
    urlFile.close()


def main():
    url = process_url("http://pythonforengineers.com/pythonforengineersbook/")
    #url = process_url("https://www.tripadvisor.in/Tourism-g303881-Munnar_Idukki_District_Kerala-Vacations.html")
    grabImages(url)

if __name__ == "__main__":
    main()
