from . import views
from django.urls import path

app_name="gangmini_hompy"


urlpatterns = [
    path('', views.index, name='index'),
    path('gangmini_hompy/project.html', views.project, name='project'),
    path('gangmini_hompy/study.html', views.study, name='study'),
]