"""webProject URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from django.conf.urls import url
from dbModel.views import *
from dbModel.testdb import testdb

from django.conf.urls.static import static
from . import settings
urlpatterns = [
    # path('admin/', admin.site.urls),
    url(r'^$',home,name='home'),
    url(r'home/$',home,name='home'),
    url(r'^test2/$',test2,name='test2'),
    url(r'^testdb$',testdb,name='testdb'),
    url(r'^proc/$',proc,name='proc'),
    url(r'^syscall/$',syscall,name='syscall'),
    url(r'^file/$',file,name='file'),
    # path('', testdb.testdb),
    # path('test3/', views.test3,name='test3'),
]

urlpatterns += static('/assets/', document_root=settings.MEDIA_ROOT)
