/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  Forecast forecast {};

  forecast.min_temp = *std::min_element(dailyWeather.begin(), dailyWeather.end());
  forecast.max_temp = *std::max_element(dailyWeather.begin(), dailyWeather.end());
  forecast.avg_temp = std::accumulate(dailyWeather.begin(), dailyWeather.end(), 0.0) / (double)dailyWeather.size();

  return forecast;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  std::vector<Forecast> result;
  std::transform(weatherData.begin(), weatherData.end(), std::back_inserter(result), compute_forecast);
  return result;
}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  auto filter_data = [](Forecast& forecast) {
    return (forecast.max_temp - forecast.min_temp <= kMaxTempRequirement) || (forecast.avg_temp < uAvgTempRequirement);
  };

  std::vector<Forecast> result = forecastData;
  result.erase(std::remove_if(result.begin(), result.end(), filter_data), result.end());

  return result;
}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  std::random_device rd;
  std::mt19937 g(rd());

  std::vector<Forecast> result = forecastData;
  std::shuffle(result.begin(), result.end(), g);

  return result;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  std::vector<Forecast> result = get_forecasts(weatherData);
  std::cout << "Before filtering: " << result.size() << " forecasts.\n";
  result = get_filtered_data(result);
  std::cout << "After filtering: " << result.size() << " forecasts.\n";
  result = get_shuffled_data(result);
  return result;
}

/* #### Please don't change this line! #### */
#include "utils.cpp"