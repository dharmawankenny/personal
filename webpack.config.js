const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const HtmlWebpackIncludeAssetsPlugin = require('html-webpack-include-assets-plugin');
const WebappWebpackPlugin = require('webapp-webpack-plugin');
const outputDir = path.join(__dirname, 'build/');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './src/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: 'Index.js',
  },
  plugins: [
    new WebappWebpackPlugin({
      logo: './src/asset/logo.png',
      prefix: 'favicons/',
      inject: 'force',
      favicons: {
        appName: 'Kenny Reida D',
        appDescription: 'Personal Website of Kenny Reida Dharmawan — Jakarta-based Frontend Engineer',
        developerName: 'Kenny Reida D.',
        background: '#000',
        theme_color: '#000',
      },
    }),
    new CopyWebpackPlugin([
      { from: 'src/index.css', to: 'css/' }
    ]),
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false
    }),
    new HtmlWebpackIncludeAssetsPlugin({
      assets: ['css/index.css'],
      append: false,
    })
  ],
  module: {
    rules: [
      {
        test: /\.(jpg|png|svg)$/,
        use: {
          loader: "file-loader",
          options: {
            name: "[path][name].[hash].[ext]",
          },
        },
      }
    ]
  },
  devServer: {
    compress: true,
    contentBase: outputDir,
    watchContentBase: true,
    port: process.env.PORT || 8000,
    historyApiFallback: true
  }
};
